const int mod = 998244353;

ll power(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod; b >>= 1;
	}
	return res;
}

void ntt(vll &a, bool invert = false) {
	int n = a.size();
	int LG = __builtin_ctz(n);
	vi rev(n);
	for (int i = 1; i < n; i++)
		rev[i] = rev[i >> 1] >> 1 | (i & 1) << (LG - 1);
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

vll convolution(vll a, vll b) {
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