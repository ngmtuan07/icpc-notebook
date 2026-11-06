ll cross(P a, P b) { return a.first * b.second - a.second * b.first; }
int half(P p) {
	return (p.second > 0 || (p.second == 0 && p.first > 0)) ? 0 : 1;
}
sort(v.begin(), v.end(), [](const P& a, const P& b) {
	int ha = half(a), hb = half(b);
	if (ha != hb) return ha < hb;
	return cross(a, b) > 0;
});