void get_longest(vector<Pt> pt) {
  int n = pt.size(), j = 2, ret = 0;
  for (int i = 0; i < n; i++) {
    while (cross(pt[i], pt[(i + 1) % n], pt[(j + 1) % n]) >
           cross(pt[i], pt[(i + 1) % n], pt[j])) {
      j = (j + 1) % n;
    }
    ret = max({ret, dis(pt[i], pt[j]), dis(pt[(i + 1) % n], pt[(j + 1) % n])});
  }
}