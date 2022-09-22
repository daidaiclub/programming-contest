struct LCA{
  vector<vector<int> > &ch, anc;
  vector<int> tin, tout;
  int n, lgn, ti;
  LCA(int _n, vector<vector<int> > &_ch, int root)
    : n(_n), ti(0), ch(_ch), tin(_n), tout(_n){
    lgn = __lg(n) + 5;
    anc.assign(n, vector<int>(lgn));
    dfs(root, root); }
  void dfs(int x, int fx){
    tin[x] = ti++;
    for(int i = 0; i < lgn; ++i)
      anc[x][i] = fx, fx = anc[fx][i];
    for(auto i : ch[x]) dfs(i, x);
    tout[x] = ti++; }
  bool isanc(int a, int x){
    return tin[a] <= tin[x] && tout[a] >= tout[x]; }
  int query(int x, int y){
    if(isanc(x, y)) return x;
    if(isanc(y, x)) return y;
    for(int i = lgn-1; i >= 0; --i)
      if(!isanc(anc[x][i], y)) x = anc[x][i];
    return anc[x][0]; }
  int qdis(int x, int y){
    int dis = !isanc(x, y) + !isanc(y, x);
    for(int i = lgn - 1; i >= 0; --i){
      if(!isanc(anc[x][i], y))
        x = anc[x][i], dis += 1<<i;
      if(!isanc(anc[y][i], x))
        y = anc[y][i], dis += 1<<i; }
    return dis; } };