const int MAXN = 1e5 + 5;
const int BUFFER_SIZE = MAXN * 50;

char buffer[BUFFER_SIZE], *buffer_ptr = buffer;
#define alloc(x, type, len)                                                    \
  type *x = (type *)buffer_ptr;                                                \
  buffer_ptr += (len) * sizeof(type)

template <int LENGTH> class SuffixArray {
public:
  int sa[LENGTH], rk[LENGTH], h[LENGTH];

  void get_sa(int *s, int n, int m) { sais(n, m, s, sa); }

  void get_height(int *s, int n) {
    for (int i = 1; i <= n; ++i) rk[sa[i]] = i;
    for (int k = 0, i = 0, j; i < n; h[rk[i++]] = k)
      for (k ? k-- : 0, j = sa[rk[i] - 1]; s[i + k] == s[j + k]; ++k) {}
  }

private:
  void induced_sort(int n, int m, int *s, bool *T, int *sa, int *cnt) {
    static int lptr[LENGTH], rptr[LENGTH];
    int tmp;
    lptr[0] = rptr[0] = 0;
    for (int i = 1; i <= m; ++i) lptr[i] = cnt[i - 1], rptr[i] = cnt[i] - 1;
    for (int i = 0; i <= n; ++i)
      sa[i] > 0 && !T[tmp = sa[i] - 1] ? sa[lptr[s[tmp]]++] = tmp : 0;
    for (int i = n; i >= 0; --i)
      sa[i] > 0 && T[tmp = sa[i] - 1] ? sa[rptr[s[tmp]]--] = tmp : 0;
  }

  bool compare(int *x, int *y, int n) {
    while (n--)
      if (*x++ != *y++) return 1;
    return 0;
  }

  void sais(int n, int m, int *s, int *sa) {
    --n;
    alloc(T, bool, n + 3);
    alloc(cnt, int, m + 3);
    alloc(lms, int, n + 3);
    alloc(tmp, int, n + 3);

    T[n] = true, ++cnt[s[n]];
    for (int i = n - 1; i >= 0; --i) {
      ++cnt[s[i]];
      T[i] = s[i] < s[i + 1] || (s[i] == s[i + 1] && T[i + 1]);
    }
    tmp[0] = 0;
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1], tmp[i] = cnt[i] - 1;

    int LMS = 0;
    for (int i = 1; i <= n; ++i) T[i] && !T[i - 1] ? lms[LMS++] = i : 0;

    memset(sa, -1, (n + 1) * sizeof(int));
    for (int i = 0; i < LMS; ++i) sa[tmp[s[lms[i]]]--] = lms[i];
    induced_sort(n, m, s, T, sa, cnt);

    alloc(len, int, n + 10);
    lms[LMS] = n + 1;
    for (int i = 0; i < LMS; ++i) len[lms[i]] = lms[i + 1] - lms[i] + 1;

    alloc(label, int, n + 10);
    int m0 = 0;
    memset(label, -1, (n + 1) * sizeof(int));
    for (int i = 1, p = -1, q = -1; i <= n; ++i) {
      if ((q = sa[i]) > 0 && T[q] && !T[q - 1]) {
        if (p == -1 || len[p] != len[q] || compare(s + p, s + q, len[p])) ++m0;
        label[q] = m0, p = q;
      }
    }
    label[n] = 0;

    alloc(s0, int, LMS + 3);
    alloc(sa0, int, LMS + 3);
    for (int i = 0, p = 0; i <= n; ++i) label[i] >= 0 ? s0[p++] = label[i] : 0;
    if (m0 + 1 == LMS) {
      for (int i = 0; i < LMS; ++i) sa0[s0[i]] = i;
    } else {
      sais(LMS, m0, s0, sa0);
    }

    tmp[0] = 0;
    for (int i = 1; i <= m; ++i) tmp[i] = cnt[i] - 1;
    memset(sa, -1, (n + 1) << 2);
    for (int i = LMS - 1; i >= 0; --i) sa[tmp[s[lms[sa0[i]]]]--] = lms[sa0[i]];
    induced_sort(n, m, s, T, sa, cnt);
  }
};
