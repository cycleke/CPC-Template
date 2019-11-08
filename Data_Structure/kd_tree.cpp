#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
typedef long long ll;

namespace KD_Tree {

  const int DIM = 2;

  inline ll sqr(int x) { return 1LL * x * x; }

  struct Point {
    int x[DIM], id, c;

    ll dist2(const Point &b) const {
      return sqr(x[0] - b.x[0]) + sqr(x[1] - b.x[1]);
    }
  };
  struct QNode {
    Point p;
    ll dis2;

    QNode() {}
    QNode(Point _p, ll _dis2) : p(_p), dis2(_dis2) {}

    bool operator < (const QNode &b) const {
      return dis2 < b.dis2 || (dis2 == b.dis2 && p.id < b.p.id);
    }
  }ans;
  struct cmpx {
    int div;
    cmpx(int _div) : div(_div) {}
    bool operator ()(const Point &a, const Point &b) {
      for (int i = 0; i < DIM; ++i)
        if (a.x[(i + div) % DIM] != b.x[(i + div) % DIM])
          return a.x[(i + div) % DIM] < b.x[(i + div) % DIM];
      return true;
    }
  };

  bool cmp(const Point &a, const Point &b, int div) {
    cmpx cp = cmpx(div);
    return cp(a, b);
  }

  struct Node {
    Point e;
    Node *lc, *rc;
    int div;
  }node_pool[MAXN], *tail, *root;
  void init() {
    tail = node_pool;
  }
  Node *build(Point *a, int l, int r, int div) {
    if (l >= r) return nullptr;
    Node *p = tail++;
    p->div = div;
    int mid = (l + r) >> 1;
    nth_element(a + l, a + mid, a + r, cmpx(div));
    p->e = a[mid];
    p->lc = build(a, l, mid, div ^ 1);
    p->rc = build(a, mid + 1, r, div ^ 1);
    return p;
  }
  void search(Point p, Node *x, int div) {
    if (!x) return;
    if (cmp(p, x->e, div)) {
      search(p, x->lc, div ^ 1);
      if (ans.dis2 == -1) {
        if (x->e.c <= p.c) ans = QNode(x->e, p.dist2(x->e));
        search(p, x->rc, div ^ 1);
      } else {
        QNode temp(x->e, p.dist2(x->e));
        if (x->e.c <= p.c && temp < ans) ans = temp;
        if (sqr(x->e.x[div] - p.x[div]) <= ans.dis2)
          search(p, x->rc, div ^ 1);
      }
    } else {
      search(p, x->rc, div ^ 1);
      if (ans.dis2 == -1) {
        if (x->e.c <= p.c) ans = QNode(x->e, p.dist2(x->e));
        search(p, x->lc, div ^ 1);
      } else {
        QNode temp(x->e, p.dist2(x->e));
        if (x->e.c <= p.c && temp < ans) ans = temp;
        if (sqr(x->e.x[div] - p.x[div]) <= ans.dis2)
          search(p, x->lc, div ^ 1);
      }
    }
  }
  void search(Point p) {
    ans.dis2 = -1;
    search(p, root, 0);
  }
} // namespace KD_Tree

void solve() {
  static KD_Tree::Point p[MAXN];
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    p[i].id = i;
    cin >> p[i].x[0] >> p[i].x[1] >> p[i].c;
  }
  KD_Tree::init();
  KD_Tree::root = KD_Tree::build(p, 0, n, 0);

  for (KD_Tree::Point q; m; --m) {
    cin >> q.x[0] >> q.x[1] >> q.c;
    KD_Tree::search(q);
    cout << KD_Tree::ans.p.x[0] << ' ' << KD_Tree::ans.p.x[1] << ' ' << KD_Tree::ans.p.c << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int o_o;
  for (cin >> o_o; o_o; --o_o) solve();

  return 0;
}
