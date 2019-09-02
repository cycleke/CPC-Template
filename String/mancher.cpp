void mancher(char *s, int n) {
  str[0] = '~';
  str[1] = '!';
  for (int i = 1; i <= n; ++i) {
    str[i * 2] = s[i];
    str[i * 2 + 1] = '!';
  }
  for (int i = 1, j = 0; i <= n; ++i) {
    if (p[j] + j > i) {
      p[i] = min(p[2 * j - i], p[j] + j - i);
    } else {
      p[i] = 1;
    }
    while (str[i + p[i]] == str[i - p[i]]) {
      ++p[i];
    }
    if (i + p[i] > j + p[j]) {
      j = i;
    }
  }
}
