struct Node {
  int x, y, id;
  bool operator < (const Node &b) const {
    if(x == b.x) return y < b.y;
    return x < b.x;}};
struct TDPO {
  vector<Node> p; vector<ll> ans;
  void init(vector<Node> _p) {
    p = _p; bit.init(MXN);
    ans.resize(p.size());
    sort(p.begin(), p.end());}
  void bulid() {
    int sz = p.size();
    for(int i = 0; i < sz; ++i) {
      ans[p[i].id] = bit.sum(p[i].y - 1);
      bit.add(p[i].y, 1);}}};