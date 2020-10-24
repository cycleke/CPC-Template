int ch[MAX_NODE][26], fail[MAX_NODE], dep[MAX_NODE], node_c;

int add_char(int u, int id) {
  if (ch[u][id] < 0) ch[u][id] = node_c++;
  return ch[u][id];
}
void build_acam() {
  queue<int> que;
  fail[0] = 0;
  for (int i = 0; i < 26; ++i)
    if (~ch[0][i]) {
      que.push(ch[0][i]);
      fail[ch[0][i]] = 0;
    } else {
      ch[0][i] = 0;
    }
  while (!que.empty()) {
    int u = que.front(), f = fail[u];
    que.pop();
    for (int i = 0; i < 26; ++i)
      if (~ch[u][i]) {
        que.push(ch[u][i]);
        fail[ch[u][i]][i] = ch[f][i];
      } else {
        ch[u][i] = ch[f][i];
      }
  }
  for (int i = 1; i < node_c; ++i) adj[fail[i]].push_back(i);
}
