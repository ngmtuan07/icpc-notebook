int n, m, q;
vector<int> g[mxN];
int low[mxN], num[mxN], timer;
vector<vector<int>> comps;
bool is_cutpoint[mxN];
vector<int> stk;
vector<int> blockcut_tree[mxN];
int up[mxN][17], depth[mxN], id[mxN];

namespace biconnected_components {
void dfs(int u, int fa) {
	int nchild = 0;
	if (!g[u].size()) {
		is_cutpoint[u] = 1;
		comps.push_back({u});
		return;
	}
	num[u] = low[u] = ++timer;
	stk.push_back(u);
	for (int v : g[u]) {
		if (v == fa) continue;
		if (num[v])
			low[u] = min(low[u], num[v]);
		else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			nchild++;
			if (low[v] >= num[u]) {
				is_cutpoint[u] = (u != fa || nchild > 1);
				comps.push_back({u});
				while (comps.back().back() != v) {
					comps.back().push_back(stk.back());
					stk.pop_back();
				}
			}
		}
	}
}

void build_tree() {
	int node_id = 0;
	for (int i = 1; i <= n; i++) {
		if (is_cutpoint[i]) {
			id[i] = ++node_id;
		}
	}
	for (auto& comp : comps) {
		int node = ++node_id;
		for (int u : comp) {
			if (!is_cutpoint[u])
				id[u] = node;
			else {
				blockcut_tree[node].push_back(id[u]);
				blockcut_tree[id[u]].push_back(node);
			}
		}
	}
}
}  // namespace biconnected_components