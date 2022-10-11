const int MXNN = 105;
const int MXNK = 10 + 1;
template<typename T>
struct SteinerTree{ // 有重要點的MST權重和, 1-base
  int n, k;
  T inf;
  vector<vector<T> > dp;
  vector<vector<pair<int, T> > > edge;
  priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > pq;
  vector<int> vis;
  void init(int _n, int _k, T _inf){ // n points, 1~k 是重要點, type T的INF
    n = _n, k = _k, inf = _inf;
    dp.assign(n + 1, vector<T>(1 << k, inf));
    edge.resize(n + 1); }
  void addEdge(int u, int v, T w){ // u <-(w)-> v
    edge[u].emplace_back(v, w);
    edge[v].emplace_back(u, w); }
  void dijkstra(int s, int cnt){
    vis.assign(n + 1, 0);
    while(!pq.empty()){
      auto [d, u] = pq.top(); pq.pop();
      if(vis[u]) continue;
      vis[u] = 1;
      for(auto &[v, w] : edge[u])
        // if(cnt > 1 && v <= k) continue;
        if(dp[v][s] > dp[u][s] + w){
          dp[v][s] = dp[u][s] + w;
          pq.push({dp[v][s], v}); } } }
  T run(){ // return total cost O(nk*2^k + n^2*2^k)
    for(int i = 1; i <= k; ++i) dp[i][1 << (i - 1)] = 0;
    for(int s = 1; s < (1 << k); ++s){
      int cnt = 0, tmp = s;
      while(tmp) cnt += (tmp & 1), tmp >>= 1;
      for(int i = k + 1; i <= n; ++i)
        for(int subs = s & (s - 1); subs; subs = s & (subs - 1))
          dp[i][s] = min(dp[i][s], dp[i][subs] + dp[i][s ^ subs]);
      for(int i = (cnt > 1 ? k + 1 : 1); i <= n; ++i)
        if(dp[i][s] != inf) pq.push({dp[i][s], i});
      dijkstra(s, cnt); }
    T res = inf;
    for(int i = 1; i <= n; ++i) res = min(res, dp[i][(1 << k) - 1]);
    return res; } };

