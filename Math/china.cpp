int china(int n, int *a, int *m) {
  int lcm = 1, res = 0;
  for (int i = 0; i < n; ++i) lcm *= m[i];
  for (int i = 0; i < n; ++i) {
    int t = lcm / m[i], x, y;
    exgcd(t, m[i], x, y);
    x = (x % m[i] + m[i]) % m[i];
    res = (res + 1LL * t * x) % lcm;
  }
  return res;
}
