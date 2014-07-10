/* 距離 */
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
/// 内積
double dot(const Point& p1, const Point& p2) {
	return real(conj(p1)*p2);
}
//----------------------------------------------------------
/// 直線lへの点pの射影
Point projection(const Point& p, const Line& l) {
	return l[0] + dot(p-l[0], l[1]-l[0]) * (l[1]-l[0]) / norm(l[1]-l[0]);
}
//----------------------------------------------------------
/// 点と点の距離
double distancePP(const Point& p, const Point& q) {
	return abs(p-q);
}
//----------------------------------------------------------
/// 点と直線の距離
double distancePL(const Point& p, const Line& l) {
	return abs(p - projection(p, l));
}
//----------------------------------------------------------
/// 点と線分の距離
/// intersectPS()はintersect.cppに定義
double distancePS(const Point& p, const Line& s) {
	const Point r = projection(p, s);
	if( intersectPS(r, s) )  return abs(r-p);
	return min( abs(s[0]-p), abs(s[1]-p) );
}

