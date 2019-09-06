struct Node {
  int len;
  Node *link, *ch[ALPHABET_SIZE];
} node_pool[MAXS], *node_it, *root, *last;

Node *new_node(int len) {
  node_it->len = len;
  return node_it++;
}
void sam_init() {
  node_it = node_pool;
  last = root = new_node(0);
}
void sam_extend(int c, int val) {
  Node *p = last, *np = new_node(p->len + 1);
  for (last = np; p && !p->ch[c]; p = p->link) p->ch[c] = np;
  if (!p) {
    np->link = root;
  } else {
    Node *q = p->ch[c];
    if (q->len == p->len + 1) {
      np->link = q;
    } else {
      Node *nq = new_node(p->len + 1);
      memcpy(nq->ch, q->ch, sizeof(q->ch));
      nq->link = q->link;
      q->link = np->link = nq;
      for (; p && p->ch[c] == q; p = p->link) p->ch[c] = nq;
    }
  }
}
