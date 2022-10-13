struct DMST {
  struct Edge{ int u, v, c; 
    Edge(int u, int v, int c):u(u),v(v),c(c){} };
  int v, e, root;
  Edge edges[MXN];
  int newV(){ return ++v; }
  void addEdge(int u, int v, int c)
   { edges[++e] = Edge(u, v, c); }
  bool con[MXN];
  int mnInW[MXN], prv[MXN], cyc[MXN], vis[MXN];
  int run(){
    memset(con, 0, 4*(V+1));
    int r1 = 0, r2 = 0;
    while(1){
      fill(mnInW, mnInW+V+1, INF);
      fill(prv, prv+V+1, -1);
      for(int i = 1; i <= e; ++i){
        int u=edges[i].u, v=edges[i].v, c=edges[i].c;
        if(u != v && v != root && c < mnInW[v])
          mnInW[v] = c, prv[v] = u; }
      fill(vis, vis+V+1, -1);
      fill(cyc, cyc+V+1, -1);
      r1 = 0;
      bool jf = 0;
      for(int i = 1; i <= v; ++i){
        if(con[i]) continue ;
        if(prv[i] == -1 && i != root) return -1;
        if(prv[i] > 0) r1 += mnInW[i];
        int s;
        for(s = i; s != -1 && vis[s] == -1; s = prv[s])
          vis[s] = i;
        if(s > 0 && vis[s] == i){
          jf = 1; int v = s;
          do{ cyc[v] = s, con[v] = 1;
            r2 += mnInW[v]; v = prv[v];
          }while(v != s);
          con[s] = 0;
      } }
      if(!jf) break ;
      for(int i = 1; i <= e; ++i){
        int &u = edges[i].u;
        int &v = edges[i].v;
        if(cyc[v] > 0) edges[i].c -= mnInW[edges[i].v];
        if(cyc[u] > 0) edges[i].u = cyc[edges[i].u];
        if(cyc[v] > 0) edges[i].v = cyc[edges[i].v];
        if(u == v) edges[i--] = edges[E--];
    } }
    return r1+r2;}};
