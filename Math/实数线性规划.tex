// 求 max{cx | Ax <= b, x >= 0}
typedef vector<double> VD;
VD simplex(vector<VD> A, VD b, VD c) {
  int n = A.size(), m = A[0].size() + 1, r = n, s = m - 1;
  vector<VD> D(n + 2, VD(m + 1, 0));
  vector<int> ix(n + m);
  for (int i = 0; i < n + m; ++i) ix[i] = i;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < m - 1; ++j) D[i][j] = -A[i][j];
    D[i][m - 1] = 1, D[i][m] = b[i];
    if (D[r][m] > D[i][m]) r = i;
  }
  for (int j = 0; j < m - 1; ++j) D[n][j] = c[j];
  D[n + 1][m - 1] = -1;
  for (double d;;) {
    if (r < n) {
      swap(ix[s], ix[r + m]);
      D[r][s] = 1 / D[r][s];
      vector<int> speed_up;
      for (int j = 0; j <= m; ++j)
        if (j != s) {
          D[r][j] *= -D[r][s];
          if (D[r][j]) speed_up.push_back(j);
        }
      for (int i = 0; i <= n + 1; ++i)
        if (i != r) {
          for (int j : speed_up) D[i][j] += D[r][j] * D[i][s];
          D[i][s] *= D[r][s];
        }
    }
    r = -1, s = -1;
    for (int j = 0; j < m; ++j)
      if ((s < 0 || ix[s] > ix[j]) &&
          (D[n + 1][j] > EPS || (D[n + 1][j] > -EPS && D[n][j] > EPS)))
        s = j;
    if (s < 0) break;
    for (int i = 0; i < n; ++i)
      if (D[i][s] < -EPS)
        if (r < 0 || (d = D[r][m] / D[r][s] - D[i][m] / D[i][s]) < -EPS ||
            (d < EPS && ix[r + m] > ix[i + m]))
          r = i;
    if (r < 0) return VD(); //无边界
  }
  if (D[n + 1][m] < -EPS) return VD(); // 无解
  VD x(m - 1);
  for (int i = m; i < n + m; ++i)
    if (ix[i] < m - 1) x[ix[i]] = D[i - m][m];
  return x; // 最优值在D[n][m]
}
