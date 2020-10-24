/*
 * 给定 n 个约束条件， m 个未知数， 求 sum(a[0][i] * x[i]) 的最大值
 * 约束条件： sum(-a[i][j] * x[j]) <= a[i][0]
 * 若要求最小值，则进行对偶：即把目标函数的系数和约束条件右边的数交换，然后把矩阵转置
 */
const int MAXN = 3e3 + 3, MAXM = 3e3 + 3, INF = ~0U >> 2;
int n, m, a[MAXN][MAXM], nxt[MAXM];
void pivot(int l, int e) {
  a[l][e] = -1;
  int t = MAXM - 1;
  for (int i = 0; i <= m; ++i)
    if (a[l][i]) nxt[t] = i, t = i;
  nxt[t] = -1;
  for (int i = 0; i <= n; ++i)
    if (i != l && (t = a[i][e])) {
      a[i][e] = 0;
      for (int j = nxt[MAXM - 1]; ~j; j = nxt[j]) a[i][j] += a[l][j] * t;
    }
}
int simplex() {
  for (;;) {
    int mi = INF, l = 0, e = 0;
    for (int i = 1; i <= m; ++i)
      if (a[0][i] > 0) {
        e = i;
        break;
      }
    if (!e) return a[0][0];
    for (int i = 1; i <= n; ++i)
      if (a[i][e] < 0 && a[i][0] < mi) mi = a[i][0], l = i;
    pivot(l, e);
  }
}
