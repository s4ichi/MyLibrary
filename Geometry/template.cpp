//外積
double cross(Point a, Point b) {
  return (a.fi * b.se - a.se * b.fi);
}

//内積
double dot(Point a, Point b) {
  return (a.fi * b.fi + a.se * b.se);
}
