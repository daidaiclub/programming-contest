struct node1 {
  double l, r;
  double sum;
} cl[maxn << 3];
struct node2 {
  double x, y1, y2;
  int flag;
} p[maxn << 3];
bool cmp(node2 a, node2 b) { return a.x < b.x; }
void pushup(int rt) {
  if (lazy[rt] > 0) cl[rt].sum = cl[rt].r - cl[rt].l;
  else cl[rt].sum = cl[rt * 2].sum + cl[rt * 2 + 1].sum;}
void build(int rt, int l, int r) {
  if (r - l > 1) {
    cl[rt].l = s[l];
    cl[rt].r = s[r];
    build(rt * 2, l, (l + r) / 2);
    build(rt * 2 + 1, (l + r) / 2, r);
    pushup(rt);
  } else {
    cl[rt].l = s[l];
    cl[rt].r = s[r];
    cl[rt].sum = 0;
  }
  return;}
void update(int rt, double y1, double y2, int flag) {
  if (cl[rt].l == y1 && cl[rt].r == y2) {
    lazy[rt] += flag;
    pushup(rt);
    return;
  } else {
    if (cl[rt * 2].r > y1) update(rt * 2, y1, min(cl[rt * 2].r, y2), flag);
    if (cl[rt * 2 + 1].l < y2)
      update(rt * 2 + 1, max(cl[rt * 2 + 1].l, y1), y2, flag);
    pushup(rt);
  }}