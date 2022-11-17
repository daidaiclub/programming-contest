ld polygonArea(vector<Point> &poly, int n) {
  ld res = 0;
  for(int i = 0, j = 0; i < n; ++i) {
    j = (i + 1) % n;
    res += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
  }
  return abs(res) / 2;
}