struct Node {
  int x, y, z;
  int ans, id;
};

bool cmp1(const Node &a, const Node &b) {
  if(a.x != b.x) return a.x < b.x;
  if(a.y != b.y) return a.y < b.y;
  return a.z < b.z;
}

bool cmp2(const Node &a, const Node &b) {
  if(a.y != b.y) return a.y < b.y;
  if(a.z != b.z) return a.z < b.z;
  return a.x < b.x;
}

void cdq(int l, int r) {
  if(l == r) return;
  int mid = (l + r) >> 1, target = 0;
  for(int i = l; i < r; ++i) {
    if(vec[i].x != vec[i + 1].x) {
      if(abs(i - mid) < abs(target - mid)) target = i;
    }
  }
  mid = target;
  cdq(l, mid);
  cdq(mid + 1, r);
  sort(vec.begin() + l, vec.begin() + mid + 1, cmp2);
  sort(vec.begin() + mid + 1, vec.begin() + r + 1, cmp2);

  int p = l;
  for(int i = mid + 1; i <= r; ++i) {
    while(p <= mid && vec[p].y < vec[i].y) {
      bit.add(vec[p].z, 1);
      p++;
    }
    vec[i].ans += bit.sum(vec[i].z - 1);
  }

  for(int i = l; i < p; ++i) bit.add(vec[i].z, -1);
}