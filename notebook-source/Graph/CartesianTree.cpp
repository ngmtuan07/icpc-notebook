// build min Cartesian tree
std::vector<int> lc(n, n), rc(n, n);
std::vector<int> stk;
for (int i = 0; i < n; i++) {
    while (!stk.empty() && b[i] < b[stk.back()]) { // flip to '>' to get max Cartesian tree
        rc[stk.back()] = lc[i];
        lc[i] = stk.back();
        stk.pop_back();
    }
    stk.push_back(i);
}

while (stk.size() > 1) {
    int x = stk.back();
    stk.pop_back();
    rc[stk.back()] = x;
}