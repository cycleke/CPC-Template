vector<int> adj[MAXN];
int dfn[MAXN], low[MAXN], dfs_c;
int bel[MAXN], size[MAXN], scc, stk[MAXN], top, in_stack[MAXN];

void tarjan(int u) {
  dfn[u] = low[u] = ++dfs_c;
  stk[top++] = u;
  in_stack[u] = 1;
  for (size_t i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (!dfn[v]) {
      tarjan(v);
      (low[v] < low[u]) && (low[u] = low[v]);
    } else if (in_stack[v] && dfn[v] < low[u]) {
      low[u] = dfn[v];
    }
  }
  if (low[u] == dfn[u]) {
    int v;
    size[++scc] = 0;
    do {
      v = stk[--top];
      in_stack[v] = 0;
      bel[v] = scc;
      ++size[scc];
    } while (u != v);
  }
}
