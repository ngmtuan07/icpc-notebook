ll a[N], st[LG + 1][N];

void pre() {
  for (int i = 1; i <= n; ++i) st[0][i] = a[i];
  for (int j = 1; j <= LG; ++j)
    for (int i = 1; i + (1 << j) - 1 <= n; ++i)
      st[j][i] = __gcd(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}

ll query(int l, int r) {
  int k = __lg(r - l + 1);
  return __gcd(st[k][l], st[k][r - (1 << k) + 1]);
}