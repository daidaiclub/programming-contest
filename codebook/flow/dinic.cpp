const int MXN = 10005;
struct Dinic{
  struct Edge{ ll v, f, re; };
  int n, s, t, lvl[MXN];
  vector<Edge> e[MXN];
  void init(int _n, int _s, int _t){
    n = _n; s = _s; t = _t;
    for(int i = 0; i < n; ++i) e[i].clear(); }
  void addEdge(int u, int v, ll f = 1){
    e[u].push_back({v, f, e[v].size()});
    e[v].push_back({u, 0, e[u].size() - 1}); }
  bool bfs(){
    memset(lvl, -1, n * 4);
    queue<int> q;
    q.push(s);
    lvl[s] = 0;
    while(!q.empty()){
      int u = q.front(); q.pop();
      for(auto &i : e[u])
        if(i.f > 0 && lvl[i.v] == -1)
          lvl[i.v] = lvl[u] + 1, q.push(i.v); }
    return lvl[t] != -1; }
  ll dfs(int u, ll nf){
    if(u == t) return nf;
    ll res = 0;
    for(auto &i : e[u])
      if(i.f > 0 && lvl[i.v] == lvl[u] + 1){
        int tmp = dfs(i.v, min(nf, i.f));
        res += tmp, nf -= tmp, i.f -= tmp;
        e[i.v][i.re].f += tmp;
        if(nf == 0) return res; }
    if(!res) lvl[u] = -1;
    return res; }
  ll run(ll res){
    while(bfs()) res += dfs(s, LLINF);
    return res; } };