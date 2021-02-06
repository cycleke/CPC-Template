// SPOJ Lexicographical Substring Search 求字典序第 k 大子串
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 90000 + 3;
const int ALPHABET = 26;

struct Node {
  int len, cnt;
  Node *link, *next[ALPHABET];
  void init(int len = 0) {
    link = nullptr;
    this->len = len, cnt = 0;
    memset(next, 0, sizeof(next));
  }
};

template <int MAX_LENGTH> class SAM {
public:
  Node *last, *root;

  void init() {
    pool_ptr = pool;
    last = root = new_node(0);
  }

  void extend(int chr) {
    Node *p = last, *np = new_node(p->len + 1);
    for (last = np; p && !p->next[chr]; p = p->link) p->next[chr] = np;
    if (!p) {
      np->link = root;
    } else {
      Node *q = p->next[chr];
      if (q->len == p->len + 1) {
        np->link = q;
      } else {
        Node *nq = new_node(p->len + 1);
        memcpy(nq->next, q->next, sizeof(q->next));
        nq->link = q->link, q->link = np->link = nq;
        for (; p && p->next[chr] == q; p = p->link) p->next[chr] = nq;
      }
    }
  }

  void toposort() {
    int size = pool_ptr - pool;
    memset(cnt, 0, size * sizeof(int));
    for (Node *it = pool; it < pool_ptr; ++it) ++cnt[it->len];
    for (int i = 1; i < size; ++i) cnt[i] += cnt[i - 1];
    for (Node *it = pool; it < pool_ptr; ++it) order[--cnt[it->len]] = it;
    for (int i = size - 1; ~i; --i) {
      Node *u = order[i];
      for (int j = 0; j < ALPHABET; ++j)
        u->cnt += u->next[j] ? u->next[j]->cnt + 1 : 0;
    }
  }

  void find_kth(int k, char *str) {
    char *ptr = str;
    Node *u = root;
    while (k) {
      for (int j = 0; j < ALPHABET; ++j) {
        if (!u->next[j]) continue;
        if (u->next[j]->cnt + 1 < k) {
          k -= u->next[j]->cnt + 1;
          continue;
        }
        --k, *ptr++ = j + 'a';
        u = u->next[j];
        break;
      }
    }
    *ptr = 0;
  }

private:
  int cnt[MAX_LENGTH * 2];
  Node pool[MAX_LENGTH * 2], *pool_ptr, *order[MAX_LENGTH * 2];

  Node *new_node(int len) {
    pool_ptr->init(len);
    return pool_ptr++;
  }
};

SAM<MAXN> sam;
char str[MAXN];

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  cin >> str;
  sam.init();
  for (char *it = str; *it; ++it) sam.extend(*it - 'a');
  sam.toposort();

  int q, k;
  for (cin >> q; q; --q) cin >> k, sam.find_kth(k, str), puts(str);

  return 0;
}
