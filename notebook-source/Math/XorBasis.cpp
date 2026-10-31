struct XorBasis {
  vector<T> basis;
  bool add(T mask) {
    for (auto u : basis) mask = min(mask, mask ^ u);
    for (auto& u : basis) u = min(u, u ^ mask);
    if (mask) {
      basis.push_back(mask);
      return true;
    }
    return false;
  }
  T getMax() {
    T res = 0;
    for (auto u : basis) res = max(res, res ^ u);
    return res;
  }
  void init() { sort(basis.begin(), basis.end()); }
  bool InSpan(T mask) {
    for (auto u : basis) mask = min(mask, mask ^ u);
    return (mask == 0);
  }
  T getK(T k)  // 0-indexed
  {
    T res = 0;
    for (int i = sz(basis) - 1; i >= 0; i--)
      if (k >> i & 1) res ^= basis[i];
    return res;
  }
};