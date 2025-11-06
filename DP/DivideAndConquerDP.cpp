const ll INF = 1e18;

void calc(int i, int l, int r, int optL, int optR) {
  if (l > r) return;
  int mid = (l + r) / 2;
  f[i][mid] = INF; // change to -INF to find max
  int opt = -1;
  for (int k = optL; k <= min(mid, optR); ++k) {
    ll c = f[i - 1][k] + cost(k + 1, mid);
    if (c < f[i][mid]) {
      f[i][mid] = c;
      opt = k;
    }
  }
  calc(i, l, mid - 1, optL, opt);
  calc(i, mid + 1, r, opt, optR);
}