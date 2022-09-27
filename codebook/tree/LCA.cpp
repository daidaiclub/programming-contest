const int MXN = 5e5+5;
struct LCA{
  int n, lgn, ti = 0;
  int anc[MXN][24], in[MXN], out[MXN];
  vector<int> g[MXN];
  void init(int _n){
    n = _n + 1, lgn = __lg(n) + 5; }
  void addEdge(int x, int y){ g[x].PB(y), g[y].PB(x); }
  void build(int x, int fx){
    in[x] = ti++;
    int cur = fx;
    for(int i = 0; i < lgn; ++i)
      anc[x][i] = cur, cur = anc[cur][i];
    for(auto i : g[x]) if(i != fx) build(i, x);
    out[x] = ti++; }
  bool isanc(int a, int x){
    return in[a] <= in[x] && out[a] >= out[x]; }
  int qlca(int x, int y){
    if(isanc(x, y)) return x;
    if(isanc(y, x)) return y;
    for(int i = lgn-1; i >= 0; --i)
      if(!isanc(anc[x][i], y)) x = anc[x][i];
    return anc[x][0]; }
  int qdis(int x, int y){
    int dis = !isanc(x, y) + !isanc(y, x);
    for(int i = lgn - 1; i >= 0; --i){
      if(!isanc(anc[x][i], y))
        x = anc[x][i], dis += 1<<i;
      if(!isanc(anc[y][i], x))
        y = anc[y][i], dis += 1<<i; }
    return dis; } };