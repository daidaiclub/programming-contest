struct EulerPath { // 有向圖
  vector<int> ans;
  vector<pll> e[MXN];
  int vis[MXN], pre[MXN];
  int in[MXN], out[MXN], s = 1, n;
  void init(int _n) { n = _n; }
  void addEdge(int u, int v, int idx) {
    e[u].PB(v, idx);
    in[v]++, out[u]++;
  }
  bool euler() {
    int cnt1 = 0, cnt2 = 0, flag = 1;
    for(int i = 1; i <= n; ++i) {
      sort(e[i].begin(), e[i].end()); // optional
      if(in[i] != out[i]) flag = 0;
      if(in[i] == out[i] - 1) s = i, cnt1++;
      if(in[i] == out[i] + 1) cnt2++;
    }
    return !flag && !(cnt1 == cnt2 && cnt1 == 1);
  }
  void dfs(int now) {
    if(out[now]){
      for(int i = pre[now]; i < (int)e[now].size(); i = pre[now]) {
        if(!vis[e[now][i].Y]) {
          vis[e[now][i].Y] = 1;
          pre[now] = i + 1;
          dfs(e[now][i].X);
        }}}
    ans.PB(now);
  }
} euler;