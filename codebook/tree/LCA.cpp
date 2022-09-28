const int MXN = 5e5+5;
struct LCA{
  int n, lgn, ti = 0;
  int anc[MXN][24], in[MXN], out[MXN];
  vector<int> g[MXN];
  void init(int _n){
    n = _n, lgn = __lg(n) + 5;
    for(int i = 0; i < n; ++i) g[i].clear(); }
  void addEdge(int u, int v){ g[u].PB(v), g[v].PB(u); }
  void build(int u, int f){
    in[u] = ti++;
    int cur = f;
    for(int i = 0; i < lgn; ++i)
      anc[u][i] = cur, cur = anc[cur][i];
    for(auto i : g[u]) if(i != f) build(i, u);
    out[u] = ti++; }
  bool isanc(int a, int u){
    return in[a] <= in[u] && out[a] >= out[u]; }
  int qlca(int u, int v){
    if(isanc(u, v)) return u;
    if(isanc(v, u)) return v;
    for(int i = lgn-1; i >= 0; --i)
      if(!isanc(anc[u][i], v)) u = anc[u][i];
    return anc[u][0]; }
  int qdis(int u, int v){
    int dis = !isanc(u, v) + !isanc(v, u);
    for(int i = lgn - 1; i >= 0; --i){
      if(!isanc(anc[u][i], v))
        u = anc[u][i], dis += 1<<i;
      if(!isanc(anc[v][i], u))
        v = anc[v][i], dis += 1<<i; }
    return dis; } };