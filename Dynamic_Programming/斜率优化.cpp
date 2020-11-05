// 树上斜率优化
// 定义dp_i 表示i节点传递到根节点的最短耗时，规定dp_root=−P。
// 有如下转移方程dp_u=dp_v+dist(u,v)^2+P,v 为 u 的祖先.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 5;

vector<pii> adj[MAXN];
ll dp[MAXN], d[MAXN];
int n, p, q[MAXN], head, tail;

inline ll S(int a, int b) { return (d[b] - d[a]) << 1; }
inline ll G(int a, int b) { return dp[b] - dp[a] + d[b] * d[b] - d[a] * d[a]; }

void dfs(int u, int from) {
  vector<int> dhead, dtail;
  if (u ^ 1) {
    while (head + 2 <= tail &&
           S(q[head + 1], q[head]) * d[u] <= G(q[head + 1], q[head]))
      dhead.push_back(q[head++]);
    int v = q[head];
    dp[u] = dp[v] + p + (d[u] - d[v]) * (d[u] - d[v]);
  }
  while (head + 2 <= tail &&
         G(u, q[tail - 1]) * S(q[tail - 1], q[tail - 2]) <=
             G(q[tail - 1], q[tail - 2]) * S(u, q[tail - 1]))
    dtail.push_back(q[--tail]);
  q[tail++] = u;
  for (pii &e : adj[u]) {
    if (e.first == from) continue;
    d[e.first] = d[u] + e.second;
    dfs(e.first, u);
  }
  --tail;
  for (int i = dtail.size() - 1; ~i; --i) q[tail++] = dtail[i];
  for (int i = dhead.size() - 1; ~i; --i) q[--head] = dhead[i];
}

void solve() {
  cin >> n >> p;
  for (int i = 1; i <= n; ++i) adj[i].clear();
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  dp[1] = -p;
  head = tail = 0;
  dfs(1, 1);

  ll ans = 0;
  for (int i = 1; i <= n; ++i)
    if (dp[i] > ans) ans = dp[i];
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int o_o;
  for (cin >> o_o; o_o; --o_o) solve();

  return 0;
}
