struct TopoSort{
  int n, m;
  vector<int> adj[N];
  int in[N];
  void init(int _n){
    n = _n, m = 0;
    for(int i = 0; i < n; i++){
      adj[i].clear();
      in[i] = 0;
    }
  }
  void addEdge(int u, int v){
    adj[u].push_back(v);
    in[v]++, m++;
  }
  bool toposort() {
    vector<int> l; // l 是拓樸排序的結果
    queue<int> q;
    for(int i = 1; i <= n; ++i)
      if(in[i] == 0) q.push(i);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      l.push_back(u);
      for(int v : adj[u]) {
        in[v]--;
        if(in[v] == 0) q.push(v);
      }
    }
    return l.size() == n;
  }
}