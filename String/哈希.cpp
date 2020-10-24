/*
 * 其他哈希：
 * 集合哈希： 可以使用元素的哈希值映射为高进制的某一位，也可以使用质数的积。
 * 树哈希： 将子树当作集合哈希，加入深度的影响
 */

const unsigned int KEY = 6151;
const unsigned int MOD = 1610612741;
// 64 位哈希参数 KEY 随意 MOD 4611686018427387847ll
unsigned int hash[MAXN], p[MAXN];

inline unsigned int get_hash(int l, int r) {
  return (hash[r] + MOD - 1ULL * hash[l - 1] * p[r - l + 1] % MOD) % MOD;
}

void init(char *s, int n) {
  p[0] = 1;
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] * KEY % MOD;
    hash[i] = (1LL * hash[i - 1] * KEY + s[i]) % MOD;
  }
}
