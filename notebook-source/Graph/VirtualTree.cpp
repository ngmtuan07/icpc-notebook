bool anc(int u, int v) { return in[u] <= in[v] && in[v] <= out[u]; }
int solve(vi& ver) {
	for (int& i : ver) matter[i] = 1;
	all = (int)ver.size();
	sort(ver.begin(), ver.end(),
		 [&](const int& a, const int& b) { return in[a] < in[b]; });
	for (int i = 1; i < all; i++) {
		ver.pb(lca(ver[i - 1], ver[i]));
	}
	sort(ver.begin(), ver.end(),
		 [&](const int& a, const int& b) { return in[a] < in[b]; });
	ver.erase(unique(ver.begin(), ver.end()), ver.end());
	vi stk;
	stk.pb(ver[0]);
	for (int i = 1; i < (int)ver.size(); i++) {
		int u = ver[i];
		while (!stk.empty() && !anc(stk.back(), u)) stk.pop_back();
		g[stk.back()].pb(edges.size());
		g[ver[i]].pb(edges.size());
		edges.push_back({stk.back(), ver[i], dis(stk.back(), ver[i])});
		stk.pb(ver[i]);
	}
	tot = 0;
	dfs(ver[0]);
	edges.clear();
	for (int i : ver) {
		matter[i] = 0;
		g[i].clear();
	}
	return tot;
}