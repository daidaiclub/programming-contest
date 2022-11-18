const int MXN = 5e5 + 5;
struct LCA{
  int n, lgn, ti = 0;
  int anc[MXN][24], in[MXN], out[MXN];
  ll ancw[MXN][24];
  vector<pll> g[MXN];
  void init(int _n) {
    n = _n, lgn = __lg(n) + 5;
    for(int i = 0; i < n; i++) g[i].clear(); }
  void addEdge(int u, int v, ll w = 1){
    g[u].PB(w, v), g[v].PB(w, u); }
  void build(int u, int f, ll w = 0) {
    in[u] = ti++;
    int cur = f;
    ll curw = w;
    for(int i = 0; i < lgn; ++i) {
      ancw[u][i] = curw, curw += ancw[cur][i];
      anc[u][i] = cur, cur = anc[cur][i]; }
    for(auto i : g[u]) if(i.Y != f) build(i.Y, u, i.X);
    out[u] = ti++; }
  bool isanc(int a, int u) {
    return in[a] <= in[u] && out[u] <= out[a]; }
  int qlca(int u, int v) {
    if(isanc(u, v)) return u;
    if(isanc(v, u)) return v;
    for(int i = lgn - 1; i >= 0; --i)
      if(!isanc(anc[u][i], v)) u = anc[u][i];
    return anc[u][0]; }
  ll qdis(int u, int v) {
    ll dis = 0;
    for(int i = lgn - 1; i >= 0; --i) {
      if(!isanc(anc[u][i], v)) {
        dis += ancw[u][i];
        u = anc[u][i]; }
      if(!isanc(anc[v][i], u)) {
        dis += ancw[v][i];
        v = anc[v][i]; } }
    if(!isanc(u, v)) dis += ancw[u][0];
    if(!isanc(v, u)) dis += ancw[v][0];
    return dis; } };
