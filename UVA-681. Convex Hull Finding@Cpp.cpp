#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

//#pragma warning(disable : 4996)

//Jiakai XU, August 4 2021, coding for OJ 210Convex Hull Finding

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
		cout << x << " " << y << endl;
	}
private:
	int x;
	int y;
};

Point* origin = nullptr;
vector<Point> pointPool;
vector<Point> pointStack;
int N = 0;

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
	static bool cmp_polar_angle(Point a, Point b) {
		const long long cp = cross_product(*origin, a, b);
		if (!cp) {
			return distance(a) < distance(b);
		}
		else if (cp > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	static double distance(Point t) {
		return distance(*origin, t);
	}
	static double distance(Point a, Point b) {
		return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY() - b.getY()) * (a.getY() - b.getY()));
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
};

void Graham() {
	sort(pointPool.begin() + 1, pointPool.end(), PointLib::cmp_polar_angle);

	//Compute
	pointStack.emplace_back(pointPool[1]);
	for (int idx = 2; idx < N; idx++) {
		while (pointStack.size() > 1 && PointLib::cross_product(pointStack[pointStack.size() - 2], pointStack[pointStack.size() - 1], pointPool[idx]) <= 0) {
			pointStack.pop_back();
		}
		pointStack.emplace_back(pointPool[idx]);
	}
	pointStack.emplace_back(*origin);

	//Print out
	int size = pointStack.size();
	cout << size << endl;
	for(int i = 0; i < size; i++) {
		pointStack[i].toString();
	}
}

int main() {
	//freopen("210.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	int testcase = 0;
	cin >> testcase;
	cout << testcase << endl;
	for (int tc = testcase - 1; tc >= 0; --tc) {
		//init
		pointPool.clear();
		pointStack.clear();
		origin = nullptr;
		N = 0;

		//readin
		cin >> N;
		int x = 0, y = 0;
		for (int n = N - 1; n >= 0; --n) {
			cin >> x >> y;
			pointPool.emplace_back(Point(x, y));
		}
		if (tc) {
			cin >> x;//Useless eat up
		}
		sort(pointPool.begin(), pointPool.end(), PointLib::cmp_y);
		origin = &pointPool[0];
		pointStack.emplace_back(pointPool[0]);
		Graham();

		//output
		if (tc) {
			cout << "-1" << endl;
		}
	}
	return 0;
}