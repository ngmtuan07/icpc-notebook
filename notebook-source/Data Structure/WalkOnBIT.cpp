template<class T>
class FenwickTree {
public:
	int n;
	vector<T> bit;
	int LOG;
	FenwickTree(int _n) {
		init(_n);
	}
	void init(int _n) {
		n = _n;
		bit = vector<T>(n, 0);
		LOG = __lg(n);
	}
	T sum(int idx) {
		assert(0 <= idx && idx < n);
		T ret = 0;
		for (; idx >= 0; idx &= idx + 1, --idx)
			ret += bit[idx];
		return ret;
	}
	T sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	void add(int idx, int delta) {
		for (; idx < n; idx |= idx + 1)
			bit[idx] += delta;
	}
	int bit_search(T v) { // lower_bound in the prefix sums array of A
		T sum = 0;
		int pos = -1;
		for(int i = LOG; i >= 0; i--){
			if (pos + (1 << i) < n && sum + bit[pos + (1 << i)] < v) {
				sum += bit[pos + (1 << i)];
				pos += (1 << i);
			}
		}
		return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
	}
};
