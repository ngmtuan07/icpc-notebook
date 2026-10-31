const int mod = 998244353;

ll power(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod; b >>= 1;
	}
	return res;
}

void ntt(V<ll> &a, bool invert = false) {
	int n = a.size();
	int LG = 31 - __builtin_clz(n);
	V<int> rev(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < LG; j++) {
			rev[i] |= (i >> (LG - 1 - j) & 1) << j;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i < rev[i]) {
			swap(a[i], a[rev[i]]);
		}
	}
	int base = power(3, (mod - 1) / n);
	for (int len = 2; len <= n; len <<= 1) {
		int wlen = invert ? power(base, n - n / len) : power(base, n / len);
		for (int i = 0; i < n; i += len) {
			ll w = 1;
			for (int j = 0; j < len / 2; j++) {
				ll u = a[i + j], v = a[i + j + len / 2] * w % mod;
				a[i + j] = (u + v < mod ? u + v : u + v - mod);
				a[i + j + len / 2] = (u >= v ? u - v : u - v + mod);
				(w *= wlen) %= mod;
			}
		}
	}
	if (invert) {
		ll divn = power(n, mod - 2);
		for (auto &x : a) {
			(x *= divn) %= mod;
		}
	}
}

V<ll> convolution(V<ll> a, V<ll> b) {
	int n = 1;
	while (n < a.size() + b.size()) n <<= 1;
	a.resize(n);
	b.resize(n);
	ntt(a);
	ntt(b);
	for (int i = 0; i < n; i++) {
		a[i] *= b[i];
		a[i] %= mod;
	}
	ntt(a, true);
	return a;
}