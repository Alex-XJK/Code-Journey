#include <iostream>
#include <vector>
using namespace std;

//#pragma warning(disable : 4996)

//Jiakai XU, August 2 2021, coding for OJ 209Isolated Segments

class Point
{
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int X, int Y) {
		x = X;
		y = Y;
	}
	void setX(int a) {
		x = a;
	}
	void setY(int a) {
		y = a;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void toString() {
		cout << "Point ( " << x << " , " << y << " )." << endl;
	}
	bool operator < (const Point& that) const {
		if(this->x == that.x) {
			return this->y < that.y;
		}
		else {
			return this->x < that.x;
		}
	}
private:
	int x;
	int y;
};


class Segment
{
public:
	Segment (Point a, Point b) {
		if(a < b) {
			sta = a;
			end = b;
		}
		else {
			sta = b;
			end = a;
		}
	}
	Point getS() {
		return sta;
	}
	Point getE() {
		return end;
	}
	void toString() {
		cout << ">> Line Segment from " << endl;
		sta.toString();
		cout << "to" << endl;
		end.toString();
		cout << endl;
	}
private:
	Point sta;
	Point end;
};

class SegLib
{
public:
	static bool isInSegment(Segment l, Point p) {
		return isInSegment(l.getS(), l.getE(), p);
	}
	static bool isInSegment(Point i, Point j, Point k) {
		int minX = min(i.getX(), j.getX());
		int maxX = max(i.getX(), j.getX());
		int minY = min(i.getY(), j.getY());
		int maxY = max(i.getY(), j.getY());
		const bool xFit = (minX <= k.getX() && k.getX() <= maxX);
		const bool yFit = (minY <= k.getY() && k.getY() <= maxY);
		return (xFit && yFit);
	}
	static long long cross_product(Segment l, Point p) {
		return cross_product(l.getS(), l.getE(), p);
	}
	static long long cross_product(Point i, Point j, Point k) {
		const long long x1 = i.getX();
		const long long y1 = i.getY();
		const long long x2 = j.getX();
		const long long y2 = j.getY();
		const long long x3 = k.getX();
		const long long y3 = k.getY();
		return ((x1 * y2) - (x2 * y1) + (x2 * y3) - (x3 * y2) + (x3 * y1) - (x1 * y3));
	}
	static bool isCrossing(Segment a, Segment b) {
		bool result = false;
		const long long cpa1 = cross_product(a, b.getS());
		const long long cpa2 = cross_product(a, b.getE());
		const long long cpb1 = cross_product(b, a.getS());
		const long long cpb2 = cross_product(b, a.getE());
		if (cpa1 * cpa2 < 0 && cpb1 * cpb2 < 0) {
			result = true;
		}
		else if (cpa1 == 0 && isInSegment(a, b.getS())) {
			result = true;
		}
		else if (cpa2 == 0 && isInSegment(a, b.getE())) {
			result = true;
		}
		else if (cpb1 == 0 && isInSegment(b, a.getS())) {
			result = true;
		}
		else if (cpb2 == 0 && isInSegment(b, a.getE())) {
			result = true;
		}
		else {
			result = false;
		}
		return result;
	}
};

vector<Segment> segmentPool;
int number = 0;

int compute() {
	int cnt = 0;
	for (int i = 0; i < number; ++i) {
		bool isIsolated = true;
		Segment a = segmentPool[i];
		for (int j = 0; j < number; ++j) {
			if(i == j) {
				continue;
			}
			Segment b = segmentPool[j];
			if(SegLib::isCrossing(a, b)) {
				isIsolated = false;
				break;
			}
		}
		if(isIsolated) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	//freopen("209.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	int testcase = 0;
	cin >> testcase;
	for (int tc = testcase - 1; tc >= 0; --tc) {
		cin >> number;
		segmentPool.clear();
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		for (int s = number - 1; s >= 0; --s) {
			cin >> x1 >> y1 >> x2 >> y2;
			segmentPool.emplace_back(Segment(Point(x1, y1), Point(x2, y2)));
		}
		cout << compute() << endl;
	}
	return 0;
}