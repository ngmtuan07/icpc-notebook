// FFT / convolution. O(n log n). Exact for results up to ~1e14 (double).
// conv(a, b)[k] = sum_{i+j=k} a[i]*b[j]
typedef complex<double> cd;
void fft(vector<cd>& a, bool inv = false) {
	int n = sz(a), L = __builtin_ctz(n);
	static vector<cd> rt(2, 1);
	for (static int k = 2; k < n; k *= 2) {
		rt.resize(2 * k);
		long double ang = acosl(-1) / k;
		rep(j, 0, k) rt[k + j] = cd(cosl(ang * j), sinl(ang * j));
	}
	vi rev(n);
	rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j, 0, k) {
			cd z = rt[j + k] * a[i + j + k];
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
	if (inv) {
		reverse(a.begin() + 1, a.end());
		for (cd& x : a) x /= n;
	}
}
vl conv(const vl& a, const vl& b) {
	if (a.empty() || b.empty()) return {};
	int m = sz(a) + sz(b) - 1, n = 1;
	while (n < m) n *= 2;
	vector<cd> f(n);
	rep(i, 0, sz(a)) f[i].real(a[i]);
	rep(i, 0, sz(b)) f[i].imag(b[i]);
	fft(f);
	for (cd& x : f) x *= x;            // (A+iB)^2: Im = 2AB
	fft(f, true);
	vl res(m);
	rep(i, 0, m) res[i] = llround(f[i].imag() / 2);
	return res;
}