int n, m, match[MAXN];
int adj[MAXN][MAXN], lx[MAXN], ly[MAXN], slack[MAXN];
int visx[MAXN], visx_c, visy[MAXN], visy_c;

bool dfs(int x) {
  visx[x] = visx_c;
  for (int y = 0; y < m; ++y)
    if (visy[y] ^ visy_c) {
      int t = lx[x] + ly[y] - adj[x][y];
      if (!t) {
        visy[y] = visy_c;
        if (match[y] < 0 || dfs(match[y])) return match[y] = x, true;
      } else
        (slack[y] > t) && (slack[y] = t);
    }
  return false;
}

int KM() {
  memset(match, -1, sizeof(int) * m);
  memset(ly, 0, sizeof(int) * m);
  for (int i = 0; i < n; ++i) {
    lx[i] = -INF;
    for (int j = 0; j < m; ++j) (adj[i][j] > lx[i]) && (lx[i] = adj[i][j]);
  }
  for (int x = 0; x < n; ++x) {
    fill(slack, slack + m, INF);
    for (;;) {
      ++visx_c, ++visy_c;
      if (dfs(x)) break;
      int d = INF;
      for (int i = 0; i < m; ++i)
        (visy[i] ^ visy_c) && (d > slack[i]) && (d = slack[i]);
      for (int i = 0; i < n; ++i) (visx[i] == visx_c) && (lx[i] -= d);
      for (int i = 0; i < m; ++i)
        (visy[i] ^ visy_c) ? slack[i] -= d : ly[i] += d;
    }
  }
  int res = 0;
  for (int i = 0; i < m; ++i) (~match[i]) && (res += adj[match[i]][i]);
  return res;
}
