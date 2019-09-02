inline ll rand64(ll x) {
  return 1ll * ((rand() << 15 ^ rand()) << 30 ^ (rand() << 15 ^ rand())) % x;
}

inline ll Pollard_rho(const ll &x, const int &y) {
  ll v0 = rand64(x - 1) + 1, v = v0, d, s = 1;
  for (register int t = 0, k = 1;;) {
    if (v = (mod_mul(v, v, x) + y) % x, s = mod_mul(s, abs(v - v0), x),
        !(v ^ v0) || !s)
      return x;
    if (++t == k) {
      if ((d = __gcd(s, x)) ^ 1) return d;
      v0 = v, k <<= 1;
    }
  }
}

ll ans;
vector<ll> factor;
void findfac(ll n) {
  if (Miller_Rabin(n)) {
    factor.push_back(n);
    return;
  }
  ll p = n;
  while (p >= n) { p = Pollard_rho(p, rand64(n - 1) + 1); }
  findfac(p);
  findfac(n / p);
}
