typedef double POINT_TYPE
typedef pair<POINT_TYPE, POINT_TYPE> point;
typedef pair<point, point> line;

POINT_TYPE cross(Point a, Point b) {
	return (a.fi * b.se - a.se * b.fi);
}

POINT_TYPE dot(Point a, Point b) {
	return (a.fi * b.fi + a.se * b.se);
}

point dist(point a, point b)
{
	return point(a.fi - b.fi, a.se - b.se);
}

bool is_cross(line a, line b)
{
	return (((cross(dist(a.se, a.fi), dist(b.fi, a.fi))) *
			 (cross(dist(a.se, a.fi), dist(b.se, a.fi)))) <= 0) &&
		(((cross(dist(b.se, b.fi), dist(a.fi, b.fi))) *
		  (cross(dist(b.se, b.fi), dist(a.se, b.fi)))) <= 0);
}
