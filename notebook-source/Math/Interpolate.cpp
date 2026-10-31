const int mod = 1e9 + 7;
const int N = 1e6 + 6;

long long inv[N], po[N], pre[N], suf[N], dakdak[N];
long long ans, num;

inline long long qpow(long long a, int b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
inline long long rv(int x) { return qpow(x, mod - 2) % mod; }
void prec() {
  inv[0] = 1;
  for (int i = 1; i <= k + 1; ++i) {
    inv[i] = (1LL * inv[i - 1] * rv(i)) % mod;
    po[i] = (po[i - 1] + qpow(i, k)) % mod;
  }
  for (int i = 1; i <= k + 1; ++i) {
    dakdak[i] = (inv[i] * inv[k + 1 - i]) % mod;
  }
}
inline long long interpolate(int x, int k, bool bf = false) {
  if (k == 0) return x;
  if (x <= k + 1 || bf) {
    return po[x];
  }
  pre[0] = x;
  suf[k + 1] = x - (k + 1);
  for (int i = 1; i <= k; i++) pre[i] = (pre[i - 1] * (x - i)) % mod;
  for (int i = k; i >= 1; i--) suf[i] = (suf[i + 1] * (x - i)) % mod;
  ans = 0;
  for (int i = 0; i <= k + 1; i++) {
    if (i == 0)
      num = suf[1];
    else if (i == k + 1)
      num = pre[k];
    else
      num = (pre[i - 1] * suf[i + 1]) % mod;  // numerator

    if ((i + k) & 1)
      ans = (ans + ((po[i] * num % mod) * dakdak[i])) % mod;
    else
      ans = (ans - ((po[i] * num % mod) * dakdak[i])) % mod;

    ans = (ans + mod) % mod;
  }
  return ans;
}