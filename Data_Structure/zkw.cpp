int tree[MAXN * 2], pre;

void init(int n, int *a) {
  memset(tree, 0, sizeof(tree));
  for (pre = 1; pre <= n; pre <<= 1) {}
  for (int i = 1; i <= n; ++i) tree[i + pre] = a[i];
  for (int i = pre; i; --i) tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
}

void update(int pos, const int &val) {
  tree[pos += pre] = val;
  for (pos >>= 1; pos; pos >>= 1)
    tree[pos] = max(tree[pos << 1], tree[pos << 1 | 1]);
}

int query(int s, int t) {
  int res = 0;
  for (s += pre - 1, t += pre + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
    if (~s & 1) res = max(res, tree[s ^ 1]);
    if (t & 1) res = max(res, tree[t ^ 1]);
  }
  return res;
}
