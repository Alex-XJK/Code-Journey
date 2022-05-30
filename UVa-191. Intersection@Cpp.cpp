#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#pragma GCC optimize(2)
//#pragma warning(disable : 4996)

//Jiakai XU, August 8 2021, coding for OJ 248Intersection

/**
 * @include <ALib.Geometry>
 * @author Alex
 */

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
		if (this->x == that.x) {
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
	Segment(Point a, Point b) {
		if (a < b) {
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

class PointLib
{
public:
	static bool cmp_y(Point a, Point b) {
		if (a.getY() == b.getY()) {
			return a.getX() < b.getX();
		}
		else {
			return a.getY() < b.getY();
		}
	}
	static double distance(Point a, Point b) {
		return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY() - b.getY()) * (a.getY() - b.getY()));
	}
	/**
	 * @return  > 0,    Anti-Clockwise;
	 *          = 0,    Collinear;
	 *          < 0,    Clockwise;
	 */
	static long long cross_product(Point i, Point j, Point k) {
		const long long x1 = i.getX();
		const long long y1 = i.getY();
		const long long x2 = j.getX();
		const long long y2 = j.getY();
		const long long x3 = k.getX();
		const long long y3 = k.getY();
		return ((x1 * y2) - (x2 * y1) + (x2 * y3) - (x3 * y2) + (x3 * y1) - (x1 * y3));
	}
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
		return PointLib::cross_product(l.getS(), l.getE(), p);
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("248.in", "r", stdin);
	//freopen("data.out", "w", stdout);

	int testcase = 0;
	cin >> testcase;
	for (int tc = testcase - 1; tc >= 0; tc--) {
		//Read in data
		int sx, sy, ex, ey;
		int lx, ly, rx, ry;
		cin >> sx >> sy >> ex >> ey >> lx >> ly >> rx >> ry;
		
		//Build Segments
		Segment target(Point(sx, sy), Point(ex, ey));	//Target Segment Line

		Segment rec_ref(Point(lx, ly), Point(rx, ry));	//Rectangle Diagonal

		Segment rec_top(Point(lx, ly), Point(rx, ly));	//Rectangle Top Line
		Segment rec_btm(Point(lx, ry), Point(rx, ry));	//Rectangle Bottom Line
		Segment rec_lft(Point(lx, ry), Point(lx, ly));	//Rectangle Left Line
		Segment rec_rit(Point(rx, ry), Point(rx, ly));	//Rectangle Right Line

		//Compute I - Whether one point is in rectangle?
		if (SegLib::isInSegment(rec_ref, target.getS()) || SegLib::isInSegment(rec_ref, target.getE())) {
			cout << "T\n";
		}
		//Compute II - Whether the Segment is crossing with one side of rectangle?
		else if (SegLib::isCrossing(target, rec_top) || SegLib::isCrossing(target, rec_btm) || SegLib::isCrossing(target, rec_lft) || SegLib::isCrossing(target, rec_rit)) {
			cout << "T\n";
		}
		else {
			cout << "F\n";
		}

	}
	//xstart ystart xend yend xleft ytop xright ybottom
	
	return 0;
}