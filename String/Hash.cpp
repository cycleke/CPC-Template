
const unsigned int KEY = 6151;
const unsigned int MOD = 1610612741;

unsigned int hash[MAXN], p[MAXN];

inline unsigned int get_hash(int l, int r) {
  return (hash[r] + MOD - 1ULL * hash[l - 1] * p[r - l + 1] % MOD) % MOD;
}

void init(char *s, int n) {
  p[0] = 1;
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] * KEY % MOD;
    hash[i] = (1LL * hash[i - 1] * KEY + s[i]) % MOD;
  }
}
