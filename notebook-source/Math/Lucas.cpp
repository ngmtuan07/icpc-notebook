
// computing nCk mod p in O(p + log_p n)
// if p isn't prime -> prime factorize p = p1^a1 * p2^a2 * ... * pr^ar
// -> calculate nCk mod p1, mod p2, ..., mod pr
// -> use chinese remainder theorem to recover nCk mod p
ll lucas(ll n, ll k, int p, vi& fact, vi& invfact) {
  ll c = 1;
  while (n || k) {
    ll a = n % p, b = k % p;
    if (a < b) return 0;
    c = c * fact[a] % p * invfact[b] % p * invfact[a - b] % p;
    n /= p;
    k /= p;
  }
  return c;
}