struct zkwflow{
  static const int MXN = 10000;
  struct Edge{ int v, f, re; ll w;};
  int n, s, t, ptr[MXN]; bool vis[MXN]; ll dis[MXN];
  vector<Edge> E[MXN];
  void init(int _n,int _s,int _t){
    n=_n,s=_s,t=_t;
    for(int i=0;i<n;i++) E[i].clear();
  }
  void addEdge(int u, int v, int f, ll w){
    E[u].push_back({v, f, E[v].size(), w});
    E[v].push_back({u, 0 ,E[u].size()-1, -w});
  }
  bool SPFA(){
    fill_n(dis, n, LLINF); memset(vis, 0, 4 * n);
    queue<int> q; q.push(s); dis[s] = 0;
    while (!q.empty()){
      int u = q.front(); q.pop(); vis[u] = false;
      for(auto &it : E[u]){
        if(it.f > 0 && dis[it.v] > dis[u] + it.w){
          dis[it.v] = dis[u] + it.w;
          if(!vis[it.v]){
            vis[it.v] = 1; q.push(it.v);
          } } } }
    return dis[t] != LLINF;
  }
  int DFS(int u, int nf){
    if(u == t) return nf;
    int res =0; vis[u] = 1;
    for(int &i = ptr[u]; i < (int)E[u].size(); ++i){
      auto &it = E[u][i];
      if(it.f>0&&dis[it.v]==dis[u]+it.w&&!vis[it.v]){
        int tf = DFS(it.v, min(nf,it.f));
        res += tf, nf -= tf, it.f -= tf;
        E[it.v][it.re].f += tf;
        if(nf == 0){ vis[u] = false; break; }
      }
    }
    return res;
  }
  pair<int,ll> flow(){
    int flow = 0; ll cost=0;
    while (SPFA()){
      memset(ptr, 0, 4 * n);
      int f = DFS(s, INF);
      flow += f; cost += dis[t] * f;
    }
    return{ flow, cost };
  }
} flow;
