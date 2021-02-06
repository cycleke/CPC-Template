// UOJ 模板题
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 3;

template <int MAX_LENGTH> class SuffixArray {
public:
  int n, sa[MAX_LENGTH], rank[MAX_LENGTH], height[MAX_LENGTH];

  void compute(char *s, int n, int m) {
    int i, p, w, j, k;
    this->n = n;
    if (n == 1) {
      sa[0] = rank[0] = height[0] = 0;
      return;
    }
    memset(cnt, 0, m * sizeof(int));
    for (i = 0; i < n; ++i) ++cnt[rank[i] = s[i]];
    for (i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
    for (i = n - 1; ~i; --i) sa[--cnt[rank[i]]] = i;
    for (w = 1; w < n; w <<= 1, m = p) {
      for (p = 0, i = n - 1; i >= n - w; --i) id[p++] = i;
      for (i = 0; i < n; ++i)
        if (sa[i] >= w) id[p++] = sa[i] - w;
      memset(cnt, 0, m * sizeof(int));
      for (i = 0; i < n; ++i) ++cnt[px[i] = rank[id[i]]];
      for (i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
      for (i = n - 1; ~i; --i) sa[--cnt[px[i]]] = id[i];
      memcpy(old_rank, rank, n * sizeof(int));
      for (i = p = 1, rank[sa[0]] = 0; i < n; ++i)
        rank[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p - 1 : p++;
    }
    for (i = 0; i < n; ++i) rank[sa[i]] = i;
    for (i = k = height[rank[0]] = 0; i < n; height[rank[i++]] = k)
      if (rank[i])
        for (k > 0 ? --k : 0, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; ++k) {}
  }

  void init_st_table(int n) {
    int lgn = lg[n];
    for (int i = 0; i < n; ++i) table[0][i] = height[i];
    for (int i = 1; i <= lgn; ++i)
      for (int j = 0, l = 1 << (i - 1); j + l < n; ++j)
        table[i][j] = min(table[i - 1][j], table[i - 1][j + l]);
  }

  int lcp(int i, int j) {
    if (i > j) swap(i, j);
    ++i;
    int lgl = lg[j - i + 1];
    return min(table[lgl][i], table[lgl][j - (1 << lgl) + 1]);
  }

private:
  int table[17][MAX_LENGTH], lg[MAX_LENGTH];
  int old_rank[MAX_LENGTH], id[MAX_LENGTH], px[MAX_LENGTH], cnt[MAX_LENGTH];

  bool cmp(int x, int y, int w) {
    return old_rank[x] == old_rank[y] && old_rank[x + w] == old_rank[y + w];
  }
};

char s[MAXN];
SuffixArray<MAXN> sa;

int main(int argc, char *argv[]) {
  int n = fread(s, 1, MAXN, stdin);
  while (s[n - 1] - 97u > 25) --n;
  for (int i = 0; i < n; ++i) s[i] -= 'a';
  s[n] = '$';
  sa.compute(s, n, 26);
  for (int i = 0; i < n; ++i) printf("%d%c", sa.sa[i] + 1, " \n"[i == n - 1]);
  for (int i = 1; i < n; ++i) printf("%d%c", sa.height[i], " \n"[i == n - 1]);
  return 0;
}
