bool on_segment(const Point &A, const Point &B, const Point &C) { return cross(A, B, C) == 0 and dot(C, A, B) <= 0; }

bool check(vector<Point> &hull, Point &a) {
  int n = sz(hull);
  if (n == 1) return hull[0] == a;
  if (n == 2) return on_segment(hull[0], hull[1], a);
  if (cross(hull[0], hull[1], a) > 0) return 0;
  if (cross(hull[n - 1], hull[0], a) >= 0) return on_segment(hull[n - 1], hull[0], a);
  int l = 2, r = n - 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (cross(hull[0], hull[mid], a) >= 0) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  debug(hull[0], hull[ans - 1], hull[ans], a, ans);
  return cross(hull[ans - 1], hull[ans], a) < 0 or on_segment(hull[ans - 1], hull[ans], a);
}
