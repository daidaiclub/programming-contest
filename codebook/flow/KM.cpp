const int MXN = 1005;
struct KM{ // 1-base
  int n, mx[MXN], my[MXN], pa[MXN];
  ll g[MXN][MXN], lx[MXN], ly[MXN], sy[MXN];
  bool vx[MXN], vy[MXN];
  void init(int _n){
    n = _n;
    MEM(g, 0); }
  void addEdge(int x, int y, ll w){ g[x][y] = w; }
  void augment(int y){
    for(int x, z; y; y = z)
      x = pa[y], z = mx[x], my[y] = x, mx[x] = y; }
  void bfs(int st){
    for(int i = 1; i <= n; ++i)
      sy[i] = LLINF, vx[i] = vy[i] = 0;
    queue<int> q; q.push(st);
    for(;;){
      while(!q.empty()){
        int x = q.front(); q.pop();
        vx[x] = 1;
        for(int y = 1; y <= n; ++y) 
          if(!vy[y]){
            ll t = lx[x] + ly[y] - g[x][y];
            if(t == 0){
              pa[y] = x;
              if(!my[y]){ augment(y); return; }
              vy[y] = 1, q.push(my[y]); }
            else if(sy[y] > t) pa[y] = x, sy[y] = t;} }
      ll cut = LLINF;
      for(int y = 1; y <= n; ++y)
        if(!vy[y] && cut > sy[y]) cut = sy[y];
      for(int j = 1; j <= n; ++j){
        if(vx[j]) lx[j] -= cut;
        if(vy[j]) ly[j] += cut;
        else sy[j] -= cut; }
      for(int y = 1; y <= n; ++y) 
        if(!vy[y] && sy[y] == 0){
          if(!my[y]){ augment(y); return; }
          vy[y]=1, q.push(my[y]); }  }  }
  ll run(){
    MEM(mx, 0), MEM(my, 0), MEM(ly, 0), MEM(lx, -0x3f);
    for(int x=1; x <= n; ++x) for(int y=1; y <= n; ++y)
        lx[x] = max(lx[x], g[x][y]);
    for(int x = 1; x <= n; ++x) bfs(x);
    ll ret = 0;
    for(int y = 1; y <= n; ++y) ret += g[my[y]][y];
    return ret; } };
