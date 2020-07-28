class MinCostFlow {
public:
  struct Result {
    int flow, cost;
  };
  struct Edge {
    int to, next, rest, cost;
  };

  vector<bool> inq;
  vector<int> head, dist, from, flow;
  vector<Edge> edges;

  MinCostFlow(int n, int m) : inq(n), head(n, -1), dist(n), from(n), flow(n) {
    edges.reserve(2 * m);
  }

  void add_edge(int u, int v, int capacity, int cost) {
    internal_add_edge(u, v, capacity, cost);
    internal_add_edge(v, u, 0, -cost);
  }

  void internal_add_edge(int u, int v, int capacity, int cost) {
    edges.push_back((Edge){v, head[u], capacity, cost});
    head[u] = edges.size() - 1;
  }

  Result augment(int source, int sink) {
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[source] = 0;
    flow[source] = INT_MAX;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      inq[u] = false;
      for (int it = head[u]; ~it; it = edges[it].next) {
        auto &e = edges[it];
        int v = e.to;
        if (e.rest > 0 && dist[u] + e.cost < dist[v]) {
          from[v] = it;
          dist[v] = dist[u] + e.cost;
          flow[v] = min(e.rest, flow[u]);
          if (!inq[v]) {
            q.push(v);
            inq[v] = true;
          }
        }
      }
    }

    if (dist[sink] == INT_MAX) return {0, 0};
    int min_flow = flow[sink];
    for (int u = sink; u != source; u = edges[from[u] ^ 1].to) {
      edges[from[u]].rest -= min_flow;
      edges[from[u] ^ 1].rest += min_flow;
    }
    return {min_flow, dist[sink]};
  }

  Result min_cost_flow(int source, int sink) {
    int flow = 0, cost = 0;
    for (;;) {
      auto result = augment(source, sink);
      if (!result.flow) break;
      flow += result.flow, cost += result.cost;
    }
    return {flow, cost};
  }
};
