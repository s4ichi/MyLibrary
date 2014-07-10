/* 交差判定、交差点取得 */
//----------------------------------------------------------
/// 定義群
#include <vector>
#include <complex>
using namespace std;
// 点
typedef complex<double> Point;
// 線
typedef vector<Point> Line;
// 許容誤差
const double EPS = 1e-9;
//----------------------------------------------------------
/// 外積
double cross(const Point& p1, const Point& p2) {
	return imag(conj(p1)*p2);
}
//----------------------------------------------------------
/// 点と直線の交差判定
bool intersectPL(const Point& p, const Line& l) {
	return fabs(cross(p-l[0], p-l[1])) < EPS;
}
//----------------------------------------------------------
/// 直線と直線の交差判定
bool intersectLL(const Line& u, const Line& v) {
	return cross(u[0]-u[1], v[0]-v[1]) > EPS ||
		   cross(u[0]-u[1], v[0]-u[1]) < EPS;
}
//----------------------------------------------------------
/// 点と線分の交差判定
bool intersectPS(const Point& p, const Line& l) {
	return abs(l[0]-p) + abs(l[1]-p) - abs(l[0]-l[1]) < EPS;
}
//----------------------------------------------------------
/// 線分と線分の交差判定
bool intersectSS(const Line& u, const Line& v) {
	return cross(u[0]-u[1], v[0]-u[1]) * cross(u[0]-u[1], v[1]-u[1]) < EPS &&
		   cross(v[0]-v[1], u[0]-v[1]) * cross(v[0]-v[1], u[1]-v[1]) < EPS;
}
//----------------------------------------------------------
/// 直線lと線分sの交差判定
bool intersectLS(const Line& l, const Line& s) {
	return cross(l[0]-l[1], l[0]-s[0]) * cross(l[0]-l[1], l[0]-s[1]) < EPS;
}
//----------------------------------------------------------
/// 直線l, mの交差点を取得
Point crossPoint(const Line& l, const Line& m) {
	double a = cross(l[1]-l[0], m[1]-m[0]);
	double b = cross(l[1]-l[0], l[1]-m[0]);
	if( abs(a) < EPS && abs(b) < EPS )  return m[0];
//	if( abs(a) < EPS ) HALT;
	return m[0] + b / a * (m[1] - m[0]);
}

