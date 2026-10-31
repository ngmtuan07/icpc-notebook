// x, y such that ax + by = gcd(a, b)
ll gcd(ll a, ll b) { return __gcd(a, b); }
ll euclid(ll a, ll b, ll &x, ll &y) {
  if (b) {
    ll d = euclid(b, a % b, y, x);
    return y -= a / b * x, d;
  }
  return x = 1, y = 0, a;
}