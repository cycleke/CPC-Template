#include <bits/stdc++.h>
using namespace std;

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

#define eps 1e-7

int simplex(vector<vector<double>> &a, vector<double> &b, vector<double> &c,
            vector<int> &basic) {
  int m = b.size(), n = c.size();
  while (true) {
    int k = -1;
    for (int j = 0; j < n; ++j)
      if (c[j] < -eps) {
        k = j;
        break;
      }
    if (k == -1) {
      double ans = 0;
      for (int i = 0; i < m; ++i) ans += c[basic[i]] * b[i];
      return 0;
    }
    int l = -1;
    for (int i = 0; i < m; ++i)
      if (a[i][k] > eps) {
        if (l == -1)
          l = i;
        else {
          double ti = b[i] / a[i][k], tl = b[l] / a[l][k];
          if (ti < tl - eps || (ti < tl + eps && basic[i] < basic[l])) l = i;
        }
      }
    if (l == -1) return -1;
    basic[l] = k;
    double tmp = 1 / a[l][k];
    for (int j = 0; j < n; ++j) a[l][j] *= tmp;
    b[l] *= tmp;
    for (int i = 0; i < m; ++i)
      if (i != l) {
        tmp = a[i][k];
        for (int j = 0; j < n; ++j) a[i][j] -= tmp * a[l][j];
        b[i] -= tmp * b[l];
      }
    tmp = c[k];
    for (int j = 0; j < n; ++j) c[j] -= tmp * a[l][j];
  }
}

int main() {
  ios::sync_with_stdio(false);
  int n, m, T;
  cin >> n >> m >> T;
  vector<double> c(n + m, 0);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    c[i] *= -1;
  }
  auto C = c;
  vector<vector<double>> a(m, vector<double>(n + m, 0));
  vector<double> b(m);
  vector<int> basic(m, -1), tmp;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) cin >> a[i][j];
    a[i][i + n] = 1;
    cin >> b[i];
    if (b[i] > -eps)
      basic[i] = i + n;
    else
      tmp.push_back(i);
  }
  if (!tmp.empty()) {
    sort(tmp.begin(), tmp.end(), [&](int i, int j) { return b[i] > b[j]; });
    vector<vector<double>> A;
    vector<double> B, C(n + m + 1, 0);
    vector<int> Basic;
    for (int i : tmp) {
      vector<double> foo;
      for (int j = 0; j < n + m; ++j) foo.push_back(-a[i][j]);
      foo.push_back(1);
      double bar = -b[i];
      for (int i = 0; i < A.size(); ++i) {
        double tmp = foo[Basic[i]];
        for (int j = 0; j <= n + m; ++j) foo[j] -= tmp * A[i][j];
        bar -= tmp * B[i];
      }
      for (int j = n + m; j >= 0; --j)
        if (-eps < foo[j] - 1 && foo[j] - 1 < eps) {
          Basic.push_back(j);
          break;
        }
      for (int i = 0; i < A.size(); ++i) {
        double tmp = A[i][Basic.back()];
        for (int j = 0; j <= n + m; ++j) A[i][j] -= tmp * foo[j];
        B[i] -= tmp * bar;
      }
      A.push_back(foo);
      B.push_back(bar);
    }
    for (int i = 0; i < A.size(); ++i)
      if (Basic[i] == n + m) {
        for (int j = 0; j < n + m; ++j) C[j] = -A[i][j];
      }
    for (int i = 0; i < m; ++i)
      if (b[i] > -eps) {
        A.push_back(a[i]);
        A[A.size() - 1].push_back(0);
        B.push_back(b[i]);
        Basic.push_back(basic[i]);
      }
    simplex(A, B, C, Basic);
    bool flag = true;
    for (int i = 0; i < m; ++i)
      if (Basic[i] == n + m) {
        if (B[i] > eps) {
          cout << "Infeasible\n";
          return 0;
        }
        int k = -1;
        for (int j = 0; j < n + m; ++j)
          if (A[i][j] > eps || A[i][j] < -eps) {
            k = j;
            break;
          }
        if (k != -1) {
          double tmp = 1 / A[i][k];
          Basic[i] = k;
          for (int j = 0; j <= n + m; ++j) A[i][j] *= tmp;
          B[i] *= tmp;
          for (int l = 0; l < m; ++l)
            if (l != i) {
              tmp = A[l][k];
              for (int j = 0; j <= n + m; ++j) A[l][j] -= tmp * A[i][j];
              B[l] -= tmp * B[i];
            }
        } else
          flag = false;
        break;
      }
    if (flag) {
      A.push_back(vector<double>(n + m, 0));
      A[A.size() - 1].push_back(1);
      B.push_back(0);
      Basic.push_back(n + m);
      for (int i = 0; i < A.size() - 1; ++i) {
        double tmp = A[i].back();
        for (int j = 0; j <= n + m; ++j) A[i][j] -= tmp * A[A.size() - 1][j];
        B[i] -= tmp * B.back();
      }
    }
    a = A;
    b = B;
    basic = Basic;
    c.push_back(0);
    for (int i = 0; i < a.size(); ++i) {
      double tmp = c[basic[i]];
      for (int j = 0; j <= n + m; ++j) c[j] -= tmp * a[i][j];
    }
  }
  auto foo = simplex(a, b, c, basic);
  if (foo == -1)
    cout << "Unbounded" << endl;
  else {
    double res = 0;
    vector<double> ans(n, 0);
    for (int i = 0; i < basic.size(); ++i)
      if (basic[i] < n) ans[basic[i]] = b[i];
    for (int j = 0; j < n; ++j) res -= C[j] * ans[j];
    cout << setprecision(8) << res << endl;
    if (T == 1) {
      for (int i = 0; i < n; ++i) cout << setprecision(8) << ans[i] << ' ';
      cout << endl;
    }
  }
  return 0;
}
