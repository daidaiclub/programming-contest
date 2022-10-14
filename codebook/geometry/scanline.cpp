ScanLine sl;
sl.add(兩點座標);
sl.run() 

template <typename T>
struct SegmentTree{
  struct Node{
    T len = 0, tag = 0;
    int nl, nr;
    Node *l, *r;
  } *root;
  vector<T> vec;
  int n;
  SegmentTree(){}
  void init(vector<T> _vec){
    vec = _vec;
    n = vec.size() - 1;
    root = build(0, n - 1);
  }
  Node* build(int l, int r){
    Node *res = new Node();
    res->nl = l, res->nr = r;
    if(l == r){
      res->l = res->r = nullptr;
      return res;
    }
    int mid = (l + r) >> 1;
    res->l = build(l, mid);
    res->r = build(mid + 1, r);
    return res;
  }
  void push(Node *cur){
    int l = cur->nl, r = cur->nr;
    if(cur->tag) cur->len = vec[r + 1] - vec[l];
    else cur->len = l == r ? 0 : cur->l->len + cur->r->len;
  }
  void update(Node *cur, int ql, int qr, int x){
    int l = cur->nl, r = cur->nr;
    if(vec[r + 1] <= ql || qr <= vec[l]) return;
    if(ql <= vec[l] && vec[r + 1] <= qr){
      cur->tag += x;
      push(cur);
      return;
    }
    update(cur->l, ql, qr, x);
    update(cur->r, ql, qr, x);
    push(cur);
  }
  void update(int l, int r, int x){
    update(root, l, r, x);
  }
};
template <typename T>
struct ScanLine{
  struct Line{
    T l, r, h, flag;
    bool operator<(const Line &rhs){
      return h < rhs.h;
    }
  };
  vector<T> vec; vector<Line> line; SegmentTree<T> seg;
  int n, cnt = 0;
  ScanLine(int _n): n(_n << 1) {
    line.resize(n), vec.resize(n);
  }
  void add(int x1, int y1, int x2, int y2){
    line[cnt] = {x1, x2, y1, 1}, line[cnt + 1] = {x1, x2, y2, -1};
    vec[cnt] = x1, vec[cnt + 1] = x2;
    cnt += 2;
  }
  T run(){
    T res = 0;
    sort(line.begin(), line.end());
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    seg.init(vec);
    for(int i = 0; i < n - 1; ++i){
      seg.update(line[i].l, line[i].r, line[i].flag);
      res += seg.root->len * (line[i + 1].h - line[i].h);
    }
    return res;
  }
};