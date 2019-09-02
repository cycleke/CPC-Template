const int MAXN = 1e7 + 5;

bool vis[MAXN];
int prime[MAXN / 10], prime_cnt;
int fac[MAXN], e[MAXN], d[MAXN], mu[MAXN], phi[MAXN];

void sieve() {
  fac[1] = 1;
  e[1] = 0;
  d[1] = 1;
  mu[1] = 1;
  phi[1] = 1;
  for (int i = 2; i < MAXN; ++i) {
    if (!vis[i]) {
      prime[prime_cnt++] = i;
      fac[i] = i;
      e[i] = 1;
      d[i] = 2;
      mu[i] = -1;
      phi[i] = i - 1;
    }
    for (int j = 0; j < prime_cnt; ++j) {
      int t = prime[j] * i;
      if (t >= MAXN) { break; }
      vis[t] = true;
      fac[t] = prime[j];
      if (i % prime[j] == 0) {
        e[t] = e[i] + 1;
        d[t] = d[i] / (e[i] + 1) * (e[t] + 1);
        mu[t] = 0;
        phi[t] = phi[i] * prime[j];
        break;
      } else {
        e[t] = 1;
        d[t] = d[i] * 2;
        mu[t] = -mu[i];
        phi[t] = phi[i] * (prime[j] - 1);
      }
    }
  }
}
