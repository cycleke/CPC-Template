// e = mu x 1
// d = 1 x 1
// sigma = d x 1
// phi = mu x id
// id = phi x 1
// id^2 = (id * phi) x id

// S = sum(f)
// sum(fxg) = sum(g(i)S(n/i))
map<int, int> mp_mu;

int S_mu(int n) {
  if (n < MAXN) return sum_mu[n];
  if (mp_mu[n]) return mp_mu[n];
  int ret = 1;
  for (int i = 2, j; i <= n; i = j + 1) {
    j = n / (n / i);
    ret -= S_mu(n / i) * (j - i + 1);
  }
  return mp_mu[n] = ret;
}

ll S_phi(int n) {
  ll res = 0;
  for (int i = 1, j; i <= n; i = j + 1) {
    j = n / (n / i);
    res += 1LL * (S_mu(j) - S_mu(i - 1)) * (n / i) * (n / i);
  }
  return (res - 1) / 2 + 1;
}
