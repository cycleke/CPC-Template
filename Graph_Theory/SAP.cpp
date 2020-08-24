struct MF {
  struct Edge {
    int to, cap, flow;
  } edges[MAXM * 4];

  vector<int> adj[MAXN];
  int n, edges_c, dep[MAXN], depc[MAXN], s, t, last[MAXN];

  void init(int _n) {
    n = _n;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    edges_c = 0;
  }

  void add_edge(int v, int u, int cap) {
    edges[edges_c] = {v, cap, 0};
    adj[u].push_back(edges_c++);
    edges[edges_c] = {u, 0, 0};
    adj[v].push_back(edges_c++);
  }

  int dfs(int u, int flow) {
    if (u == t || !flow) return flow;
    int v, e, temp, res = 0;
    for (int &i = last[u]; i < (int)adj[u].size(); ++i) {
      e = adj[u][i];
      v = edges[e].to;
      if (edges[e].cap == edges[e].flow) continue;
      if (dep[v] != dep[u] - 1) continue;
      temp = dfs(v, min(flow, edges[e].cap - edges[e].flow));
      edges[e].flow += temp, edges[e ^ 1].flow -= temp;
      res += temp, flow -= temp;
      if (!flow) return res;
      if (!dep[s]) return res;
    }
    last[u] = 0;
    if (!(--depc[dep[u]])) dep[s] = n + 1;
    ++depc[++dep[u]];
    return res;
  }
  int max_flow(int s, int t) {
    this->s = s, this->t = t;

    static queue<int> que;
    memset(dep + 1, 0, sizeof(int) * n);
    memset(depc + 1, 0, sizeof(int) * n);
    memset(last + 1, 0, sizeof(int) * n);
    while (!que.empty()) que.pop();
    dep[t] = 1, que.push(t);

    while (!que.empty()) {
      int u = que.front();
      que.pop();
      ++depc[dep[u]];
      for (int i = 0, v; i < (int)adj[u].size(); ++i) {
        v = edges[adj[u][i]].to;
        if (dep[v]) continue;
        dep[v] = dep[u] + 1;
        que.push(v);
      }
    }

    int res = 0;
    while (dep[s] <= n) res += dfs(s, INT_MAX);
    return res;
  }
};
