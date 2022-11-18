int dfn[MXN], low[MXN], cut[MXN];
int idx;
vector<int> e[MXN];

void tarjan(int u, int fa) {
  dfn[u] = low[u] = ++idx;
  int child = 0;
  for (int v : e[u]) {
    if (!dfn[v]) {
      tarjan(v, fa);
      low[u] = min(low[u], low[v]);
      if (low[v] >= dfn[u] && u != fa)
        cut[u] = 1;
      if(u == fa)
        child++;
    }
    low[u]= min(low[u], dfn[v]);
  }
  if (child >= 2&& u == fa) cut[u]=1;
}