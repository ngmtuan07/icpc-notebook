#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll get_rand(ll l, ll r) {
    return uniform_int_distribution<ll> (l, r)(rng);
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cerr << "\n[Time]: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
    return 0;
}
