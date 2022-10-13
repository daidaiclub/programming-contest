const int MXN = 200005;
template <typename T>
struct HeavyDecompose{ // 1-base, Need "ulimit -s unlimited"
  SegmentTree<T> st;
  vector<T> vec, tmp; // If tree point has weight
  vector<int> e[MXN];
  int sz[MXN], dep[MXN], fa[MXN], h[MXN];
  int cnt = 0, r = 0, n = 0;
  int root[MXN], id[MXN];
  void addEdge(int a, int b){
    e[a].emplace_back(b);
    e[b].emplace_back(a);
  }
  HeavyDecompose(int n, int r): n(n), r(r){
    vec.resize(n + 1); tmp.resize(n + 1);
  }
  void build(){
    dfs1(r, 0, 0);
    dfs2(r, r);
    st.init(tmp); // SegmentTree Need Add Method
  }
  void dfs1(int x, int f, int d){
    dep[x] = d, fa[x] = f, sz[x] = 1, h[x] = 0;
    for(int i : e[x]){
      if(i == f) continue;
      dfs1(i, x, d + 1);
      sz[x] += sz[i];
      if(sz[i] > sz[h[x]]) h[x] = i;
    }
  }
  void dfs2(int x, int f){
    id[x] = cnt++, root[x] = f, tmp[id[x]] = vec[x];
    if(!h[x]) return;
    dfs2(h[x], f);
    for(int i : e[x]){
      if(i == fa[x] || i == h[x]) continue;
      dfs2(i, i);
    }
  }
  void update(int x, int y, T v){
    while(root[x] != root[y]){
      if(dep[root[x]] < dep[root[y]]) swap(x, y);
      st.update(id[root[x]], id[x], v);
      x = fa[root[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    st.update(id[x], id[y], v);
  }
  T query(int x, int y){
    T res = 0;
    while(root[x] != root[y]){
      if(dep[root[x]] < dep[root[y]]) swap(x, y);
      res = (st.query(id[root[x]], id[x]) + res) % MOD;
      x = fa[root[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    res = (st.query(id[x], id[y]) + res) % MOD;
    return res;
  }
  void update(int x, T v){
    st.update(id[x], id[x] + sz[x] - 1, v);
  }
  T query(int x){
    return st.query(id[x], id[x] + sz[x] - 1);
  }
  int getLca(int x, int y){
    while(root[x] != root[y]){
      if(dep[root[x]] > dep[root[y]]) x = fa[root[x]];
      else y = fa[root[y]];
    }
    return dep[x] > dep[y] ? y : x;
  }
};