//最长双回文串
struct PT {
  char s[MAXL];
  int fail[MAXL], ch[26][MAXL], l[MAXL], dep[MAXL], lst, nc, n;
  void init() {
    l[0] = 0;
    l[1] = -1;
    fail[0] = fail[1] = 1;
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < nc; ++j) { ch[i][j] = 0; }
    }
    for (int i = 2; i < nc; ++i) {
      l[i] = 0;
      fail[i] = 0;
    }

    lst = 0;
    nc = 2;
    n = 0;
    s[0] = '#';
  }

  int insert(char c) {
    int id = c - 'a';
    s[++n] = c;
    while (s[n - l[lst] - 1] != s[n]) { lst = fail[lst]; }
    if (ch[id][lst] == 0) {
      l[nc] = l[lst] + 2;
      int f = fail[lst];
      while (s[n - l[f] - 1] != s[n]) { f = fail[f]; }
      fail[nc] = ch[id][f];
      dep[nc] = dep[fail[nc]] + 1;
      ch[id][lst] = nc;
      ++nc;
    }
    lst = ch[id][lst];
    return lst;
  }
} pt;

char S[MAXL];
int len[MAXL];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  int n = strlen(S);
  pt.init();
  for (int i = 0; i < n; ++i) { len[i] = pt.l[pt.insert(S[i])]; }
  pt.init();
  int ans = 0;
  for (int i = n - 1; i; --i) {
    ans = max(ans, len[i - 1] + pt.l[pt.insert(S[i])]);
  }
  cout << ans << "\n";

  return 0;
}
