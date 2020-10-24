#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e4 + 4, M = 2e5 + 5, INF = 0x3f3f3f3f;
int n, m, s, t;

struct qxx {
  int nex, t, v;
};
qxx e[M * 2];
int h[N], cnt = 1;
void add_path(int f, int t, int v) { e[++cnt] = (qxx){h[f], t, v}, h[f] = cnt; }
void add_flow(int f, int t, int v) {
  add_path(f, t, v);
  add_path(t, f, 0);
}

int ht[N], ex[N], gap[N]; // 高度；超额流；gap 优化
bool bfs_init() {
  memset(ht, 0x3f, sizeof(ht));
  queue<int> q;
  q.push(t), ht[t] = 0;
  while (q.size()) { // 反向 BFS, 遇到没有访问过的结点就入队
    int u = q.front();
    q.pop();
    for (int i = h[u]; i; i = e[i].nex) {
      const int &v = e[i].t;
      if (e[i ^ 1].v && ht[v] > ht[u] + 1) ht[v] = ht[u] + 1, q.push(v);
    }
  }
  return ht[s] != INF; // 如果图不连通，返回 0
}
struct cmp {
  bool operator()(int a, int b) const { return ht[a] < ht[b]; }
};                                        // 伪装排序函数
priority_queue<int, vector<int>, cmp> pq; // 将需要推送的结点以高度高的优先
bool vis[N];                              // 是否在优先队列中
int push(int u) { // 尽可能通过能够推送的边推送超额流
  for (int i = h[u]; i; i = e[i].nex) {
    const int &v = e[i].t, &w = e[i].v;
    if (!w || ht[u] != ht[v] + 1) continue;
    int k = min(w, ex[u]); // 取到剩余容量和超额流的最小值
    ex[u] -= k, ex[v] += k, e[i].v -= k, e[i ^ 1].v += k; // push
    if (v != s && v != t && !vis[v])
      pq.push(v), vis[v] = 1; // 推送之后，v 必然溢出，则入堆，等待被推送
    if (!ex[u]) return 0; // 如果已经推送完就返回
  }
  return 1;
}
void relabel(int u) { // 重贴标签（高度）
  ht[u] = INF;
  for (int i = h[u]; i; i = e[i].nex)
    if (e[i].v) ht[u] = min(ht[u], ht[e[i].t]);
  ++ht[u];
}
int hlpp() {                 // 返回最大流
  if (!bfs_init()) return 0; // 图不连通
  ht[s] = n;
  memset(gap, 0, sizeof(gap));
  for (int i = 1; i <= n; i++)
    if (ht[i] != INF) gap[ht[i]]++; // 初始化 gap
  for (int i = h[s]; i; i = e[i].nex) {
    const int v = e[i].t, w = e[i].v; // 队列初始化
    if (!w) continue;
    ex[s] -= w, ex[v] += w, e[i].v -= w, e[i ^ 1].v += w; // 注意取消 w 的引用
    if (v != s && v != t && !vis[v]) pq.push(v), vis[v] = 1; // 入队
  }
  while (pq.size()) {
    int u = pq.top();
    pq.pop(), vis[u] = 0;
    while (push(u)) { // 仍然溢出
      // 如果 u 结点原来所在的高度没有结点了，相当于出现断层
      if (!--gap[ht[u]])
        for (int i = 1; i <= n; i++)
          if (i != s && i != t && ht[i] > ht[u] && ht[i] < n + 1) ht[i] = n + 1;
      relabel(u);
      ++gap[ht[u]]; // 新的高度，更新 gap
    }
  }
  return ex[t];
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  for (int i = 1, u, v, w; i <= m; i++) {
    scanf("%d%d%d", &u, &v, &w);
    add_flow(u, v, w);
  }
  printf("%d", hlpp());
  return 0;
}
