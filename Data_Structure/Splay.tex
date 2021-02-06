#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 2e5 + 10;

struct Node {
  long long sum;
  int id, val, lazy, size;
  Node *fa, *ch[2];
} node_pool[MAXN], *pool_it, *root, *nil;

Node *newnode(int id, int val) {
  pool_it->id = id;
  pool_it->lazy = 0;
  pool_it->size = 1;
  pool_it->sum = pool_it->val = val;
  pool_it->fa = pool_it->ch[0] = pool_it->ch[1] = nil;
  return pool_it++;
}

void maintain(Node *u) {
  if (u == nil) { return; }
  u->size = u->ch[0]->size + u->ch[1]->size + 1;
  u->sum = u->ch[0]->sum + u->ch[1]->sum + u->val;
}

void push_down(Node *u) {
  if (u->lazy) {
    if (u->ch[0] != nil) {
      u->ch[0]->val += u->lazy;
      u->ch[0]->sum += 1LL * u->ch[0]->size * u->lazy;
      u->ch[0]->lazy += u->lazy;
    }
    if (u->ch[1] != nil) {
      u->ch[1]->val += u->lazy;
      u->ch[1]->sum += 1LL * u->ch[1]->size * u->lazy;
      u->ch[1]->lazy += u->lazy;
    }
    u->lazy = 0;
  }
}

inline void rot(Node *u) {
  Node *f = u->fa, *ff = f->fa;
  int d = u == f->ch[1];
  push_down(f);
  push_down(u);
  if ((f->ch[d] = u->ch[d ^ 1]) != nil) f->ch[d]->fa = f;
  if ((u->fa = ff) != nil) ff->ch[f == ff->ch[1]] = u;
  f->fa = u;
  u->ch[d ^ 1] = f;
  maintain(f);
  maintain(u);
}

void splay(Node *u, Node *target) {
  for (Node *f; u->fa != target; rot(u))
    if ((f = u->fa)->fa != target) {
      ((u == f->ch[1]) ^ (f == f->fa->ch[1])) ? rot(u) : rot(f);
    }
  if (target == nil) root = u;
}

inline void insert(int id, int val) {
  if (root == nil) {
    root = newnode(id, val);
    return;
  }
  Node *u = root;
  while (u != nil) {
    int d = id >= u->id;
    ++u->size;
    push_down(u);
    u->sum += val;
    if (u->ch[d] != nil) {
      u = u->ch[d];
    } else {
      u->ch[d] = newnode(id, val);
      u->ch[d]->fa = u;
      u = u->ch[d];
      break;
    }
  }
  splay(u, nil);
}

inline Node *find_pred(int id) {
  Node *u = root, *ret = nil;
  while (u != nil) {
    push_down(u);
    if (u->id < id) {
      ret = u;
      u = u->ch[1];
    } else {
      u = u->ch[0];
    }
  }
  return ret;
}

inline Node *find_succ(int id) {
  Node *u = root, *ret = nil;
  while (u != nil) {
    push_down(u);
    if (u->id > id) {
      ret = u;
      u = u->ch[0];
    } else {
      u = u->ch[1];
    }
  }
  return ret;
}

Node *find_kth(int k) {
  Node *u = root;
  while (u != nil) {
    push_down(u);
    if (u->ch[0]->size + 1 == k) {
      splay(u, nil);
      return u;
    }
    if (u->ch[0]->size >= k) {
      u = u->ch[0];
    } else {
      k -= u->ch[0]->size + 1;
      u = u->ch[1];
    }
  }
  return nil;
}

Node *range(int l, int r) {
  Node *pred = find_pred(l);
  Node *succ = find_succ(r);

  splay(pred, nil);
  splay(succ, root);
  push_down(pred);
  push_down(succ);
  return root->ch[1]->ch[0];
}

int main() {

  // freopen("input.txt", "r", stdin);

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  pool_it = node_pool;
  nil = pool_it++;
  nil->ch[0] = nil->ch[1] = nil->fa = nil;
  nil->id = -1;
  nil->val = 0;
  root = nil;

  insert(-0x3fffffff, 0);
  insert(0x3fffffff, 0);

  return 0;
}
