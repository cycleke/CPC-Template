// CCPC Final 2017 F
// sum(P(s)) = 1, P(s) >= 0
// max and equal (sum(P(s)) | i in s)
#include <bits/stdc++.h>
using namespace std;

typedef long double db;
const int MAXN = 3000;
const int MAXM = 3000;
const db EPS = 1e-9;
const db INF = 1e200;

namespace LP {
db a[MAXM][MAXN];
int idA[MAXN], idB[MAXN];
int m, n;

void put_out(int x) {
  if (x == 0)
    printf("Infeasible\n");
  else
    printf("Unbounded\n");
  exit(0);
}
void pivot(int xA, int xB) {
  swap(idA[xA], idB[xB]);
  static int next[MAXN];
  int i, j, last = MAXN - 1;
  db tmp = -a[xB][xA];
  a[xB][xA] = -1.0;
  for (j = 0; j <= n; j++)
    if (fabs(a[xB][j]) > EPS) a[xB][last = next[last] = j] /= tmp;
  next[last] = -1;

  for (i = 0; i <= m; i++)
    if (i != xB && fabs(tmp = a[i][xA]) > EPS)
      for (a[i][xA] = 0.0, j = next[MAXN - 1]; ~j; j = next[j])
        a[i][j] += tmp * a[xB][j];
}
db calc() {
  int xA, xB;
  db Max, tmp;
  while (1) {
    xA = n + 1, idA[xA] = n + m + 1;
    for (int i = 1; i <= n; i++)
      if (a[0][i] > EPS && idA[i] < idA[xA]) xA = i;

    if (xA == n + 1) return a[0][0];
    xB = m + 1, idB[xB] = n + m + 1, Max = -INF;
    for (int i = 1; i <= m; i++)
      if (a[i][xA] < -EPS && ((tmp = a[i][0] / a[i][xA]) > Max + EPS ||
                              (tmp > Max - EPS && idB[i] < idB[xB])))
        Max = tmp, xB = i;

    if (xB == m + 1) put_out(1);

    pivot(xA, xB);
  }
  return a[0][0];
}
db solve() {
  for (int i = 1; i <= n; i++) idA[i] = i;
  for (int i = 1; i <= m; i++) idB[i] = n + i;
  static db tmp[MAXN];
  db Min = 0.0;
  int l;
  for (int i = 1; i <= m; i++)
    if (a[i][0] < Min) Min = a[i][0], l = i;
  if (Min > -EPS) return calc();

  idA[++n] = 0;
  for (int i = 1; i <= m; i++) a[i][n] = 1.0;
  for (int i = 0; i <= n; i++) tmp[i] = a[0][i], a[0][i] = 0.0;
  a[0][n] = -1.0;

  pivot(n, l);

  if (calc() < -EPS) put_out(0);
  for (int i = 1; i <= m; i++)
    if (!idB[i]) {
      for (int j = 1; j <= n; j++)
        if (fabs(a[0][j]) > EPS) {
          pivot(j, i);
          break;
        }
      break;
    }

  int xA;
  for (xA = 1; xA <= n; xA++)
    if (!idA[xA]) break;
  for (int i = 0; i <= m; i++) a[i][xA] = a[i][n];
  idA[xA] = idA[n], n--;

  for (int i = 0; i <= n; i++) a[0][i] = 0.0;
  for (int i = 1; i <= m; i++)
    if (idB[i] <= n) {
      for (int j = 0; j <= n; j++) a[0][j] += a[i][j] * tmp[idB[i]];
    }

  for (int i = 1; i <= n; i++)
    if (idA[i] <= n) a[0][i] += tmp[idA[i]];
  return calc();
}
db ans[MAXN];
void findAns() {
  for (int i = 1; i <= n; i++) ans[i] = 0.0;
  for (int i = 1; i <= m; i++)
    if (idB[i] <= n) ans[idB[i]] = a[i][0];
}
void work() {
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) a[i][j] *= -1;
  printf("%.10f\n", -double(solve()));
}
} // namespace LP

void solve() {
  static int n, m, g[10];
  static vector<int> con[10], able;

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", g + i);
    con[i].clear();
  }

  if (n == 1) {
    printf("%.10f\n", m >= g[0] ? 1.0 : 0.0);
    return;
  }

  able.clear();
  for (int s = 0; s < (1 << n); ++s) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
      if (s >> i & 1) sum += g[i];
    if (sum > m) continue;

    able.push_back(s);
    for (int i = 0; i < n; ++i)
      if (s >> i & 1) con[i].push_back(able.size());
  }

  LP::n = able.size();
  LP::m = 0;

  for (int step = 0; step < n; ++step) {
    int &f = ++LP::m;
    for (int i = 0; i <= LP::n; ++i) LP::a[f][i] = 0;
    for (int x : con[step]) ++LP::a[f][x];
    if (step + 1 < n) {
      for (int x : con[step + 1]) --LP::a[f][x];
    } else {
      for (int x : con[0]) --LP::a[f][x];
    }
  }

  ++LP::m;
  LP::a[LP::m][0] = 1;
  for (int i = 1; i <= LP::n; ++i) LP::a[LP::m][i] = 1;

  ++LP::m;
  LP::a[LP::m][0] = -1;
  for (int i = 1; i <= LP::n; ++i) LP::a[LP::m][i] = -1;

  for (int i = 0; i <= LP::n; ++i) LP::a[0][i] = 0;
  for (int x : con[0]) ++LP::a[0][x];

  static db a2[MAXM][MAXN];
  for (int i = 1; i <= LP::m; ++i)
    for (int j = 1; j <= LP::n; ++j) a2[i][j] = LP::a[i][j];
  for (int i = 1; i <= LP::m; ++i)
    for (int j = 1; j <= LP::n; ++j) LP::a[j][i] = a2[i][j];
  swap(LP::n, LP::m);
  for (int i = 1; i <= max(LP::n, LP::m); ++i) swap(LP::a[0][i], LP::a[i][0]);
  LP::a[0][0] = 0;
  for (int i = 1; i <= LP::m; ++i)
    for (int j = 1; j <= LP::n; ++j) LP::a[i][j] *= -1;
  for (int i = 1; i <= LP::m; ++i) LP::a[i][0] *= -1;
  for (int i = 1; i <= LP::n; ++i) LP::a[0][i] *= -1;

  LP::work();
}

int main() {
  int o_o;
  scanf("%d", &o_o);
  for (int i = 1; i <= o_o; ++i) {
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
