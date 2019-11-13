void get_next(char *S, int *nxt, int n) {
  nxt[0] = -1;
  int j = -1;
  for (int i = 1; i < n; ++i) {
    while ((~j) && S[j + 1] != S[i]) j = nxt[j];
    nxt[i] = (S[j + 1] == S[i]) ? (++j) : j;
  }
}

int pattern(char *S, char *T, int *nxt, int n, int m) {
  int j = -1;
  for (int i = 0; i < m; ++i) {
    while ((~j) && S[j + 1] != T[i]) j = nxt[j];
    j += S[j + 1] == T[i];
    if (j == n - 1) return i - n + 1;
  }
  return -1;
}
