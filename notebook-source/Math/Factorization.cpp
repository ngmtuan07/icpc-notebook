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
bool is_prime(long long n) {
  if (n <= 1) return false;
  for (int a : {2, 3, 5, 13, 19, 73, 193, 407521, 299210837}) {
    if (n == a) return true;
    if (n % a == 0) return false;
  }
  long long d = n - 1;
  while (!(d & 1)) d >>= 1;
  for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    long long t = d, y = ipow(a, t, n);
    while (t != n - 1 && y != 1 && y != n - 1) y = mul(y, y, n), t <<= 1;
    if (y != n - 1 && !(t & 1)) return false;
  }
  return true;
}

long long pollard(long n) {
  auto f = [n](long x) { return mul(x, x, n) + 1; };
  long long x = 0, y = 0, t = 0, prd = 2, i = 1, q;
  while (t++ % 40 || gcd(prd, n) == 1) {
    if (x == y) x = ++i, y = f(x);
    if ((q = mul(prd, max(x, y) - min(x, y), n))) prd = q;
    x = f(x), y = f(f(y));
  }
  return gcd(prd, n);
}
vector<long long> factor(long n) {
  if (n == 1) return {};
  if (is_prime(n)) return {n};
  long x = pollard(n);
  auto l = factor(x), r = factor(n / x);
  l.insert(l.end(), r.begin(), r.end());
  return l;
}
