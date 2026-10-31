const ll mod = 1000000007, LIM = 200000;
ll* inv = new ll[LIM] - 1; inv[1] = 1;
for(ll i = 2; i < LIM; ++i) inv[i] = mod - (mod / i) * inv[mod % i] % mod;