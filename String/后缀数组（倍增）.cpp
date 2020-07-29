char s[MAXN];
int sa[MAXN], x[MAXN], y[MAXN], c[MAXN];
int rk[MAXN], height[MAXN], st[17][MAXN], lg[MAXN];

bool cmp(int *r, int i, int j, int l) {
  return r[i] == r[j] && r[i + l] == r[j + l];
}
void da(char *s, int n, int m) {
  int i, j, p;
  for (i = 0; i < m; ++i) c[i] = 0;
  for (i = 0; i < n; ++i) ++c[x[i] = s[i]];
  for (i = 1; i < m; ++i) c[i] += c[i - 1];
  for (i = n - 1; ~i; --i) sa[--c[x[i]]] = i;
  for (p = j = 1; p < n; j <<= 1, m = p) {
    for (p = 0, i = n - j; i < n; ++i) y[p++] = i;
    for (i = 0; i < n; ++i)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < m; ++i) c[i] = 0;
    for (i = 0; i < n; ++i) ++c[x[y[i]]];
    for (i = 1; i < m; ++i) c[i] += c[i - 1];
    for (i = n - 1; ~i; --i) sa[--c[x[y[i]]]] = y[i];
    for (swap(x, y), p = 1, x[sa[0]] = 0, i = 1; i < n; ++i)
      x[sa[i]] = cmp(y, sa[i], sa[i - 1], j) ? p - 1 : p++;
  }
}

void get_height(char *s, int n) {
  int i, j, k;
  for (i = 0; i < n; ++i) rk[sa[i]] = i;
  for (i = k = height[rk[0]] = 0; i < n; height[rk[i++]] = k)
    if (rk[i])
      for (k > 0 ? --k : 0, j = sa[rk[i] - 1]; s[i + k] == s[j + k]; ++k) {}
}

void init_st_table(int n) {
  int lgn = lg[n];
  for (int i = 0; i < n; ++i) st[0][i] = height[i];
  for (int i = 1; i <= lgn; ++i)
    for (int j = 0; j + (1 << i - 1) < n; ++j)
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
}

int lcp(int i, int j) {
  if (i > j) swap(i, j);
  ++i;
  int lgl = lg[j - i + 1];
  return min(st[lgl][i], st[lgl][j - (1 << lgl) + 1]);
}
