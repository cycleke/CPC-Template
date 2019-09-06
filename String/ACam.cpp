int ch[MAX_NODE][26], fail[MAX_NODE], dep[MAX_NODE], node_c;

int add_char(int u, int id) {
  if (ch[u][id] < 0) ch[u][id] = node_c++;
  return ch[u][id];
}
void build_acam() {
  queue<int> que;
  FOR(i, 0, 26)
    if (~ch[0][i]) {
      que.push(ch[0][i]);
      fail[ch[0][i]] = 0;
      dep[ch[0][i]] = 1;
    } else {
      ch[0][i] = 0;
    }
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    FOR(i, 0, 26)
      if (~ch[u][i]) {
        que.push(ch[u][i]);
        fail[ch[u][i]] = ch[fail[u]][i];
        dep[ch[u][i]] = dep[u] + 1;
      } else {
        ch[u][i] = ch[fail[u]][i];
      }
  }
  FOR(i, 1, node_c) adj[fail[i]].push_back(i);
}
