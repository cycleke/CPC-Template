// C(n, m) = C(n / p, m / p) * C(n % p, m % p) (mod p)
ll lucas(ll n, ll k, int p) {
  ll ret = 1;
  while (n && k) {
    ll nn = n % p, kk = k % p;
    if (nn < kk) return 0;
    ret = ret * f[nn] * mpow(f[kk] * f[nn - kk] % p, p - 2, p) % p;
    n /= p, k /= p;
  }
  return ret;
}
