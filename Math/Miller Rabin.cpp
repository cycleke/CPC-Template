inline ll mod_mul(const ll &a, const ll &b, const ll &mod) {
  ll k = (ll)((1.0L * a * b) / (1.0L * mod)), t = a * b - k * mod;
  t -= mod;
  while (t < 0) t += mod;
  return t;
}
inline ll mod_pow(ll a, ll b, const ll &mod) {
  ll res = 1;
  for (; b; b >>= 1, a = mod_mul(a, a, mod))
    (b & 1) && (res = mod_mul(res, a, mod));
  return res;
}

inline bool check(const ll &x, const ll &p) {
  if (!(x % p) || mod_pow(p % x, x - 1, x) ^ 1) return false;
  ll k = x - 1, t;
  while (~k & 1) {
    if (((t = mod_pow(p % x, k >>= 1, x)) ^ 1) && (t ^ (x - 1))) return false;
    if (!(t ^ (x - 1))) return true;
  }
  return true;
}

inline bool Miller_Rabin(const ll &x) {
  if (x < 2) return false;
  static const int p[12] = {2, 3, 5, 7, 11, 13, 17, 19, 61, 2333, 4567, 24251};
  for (register int i = 0; i < 12; ++i) {
    if (!(x ^ p[i])) return true;
    if (!check(x, p[i])) return false;
  }
  return true;
}
