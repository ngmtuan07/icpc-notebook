struct maximum_bipartite_matching {
    int n, m, turn, matched;
    vector<int> matchR, matchL, vis;
    vector< vector<int> > adj;
    vector< pair<int, int> > edges;
    maximum_bipartite_matching(int _n, int _m): n(_n), m(_m), matchL(n + 1), matchR(m + 1, -1), vis(n + 1), adj(n + 1), turn(0), matched(0) {
    }

    void add_edge(int u, int v) {
        edges.push_back({u, v});
    }

    bool dfs(int u) {
        if (vis[u] == turn) return false;
        vis[u] = turn;

        for(int v: adj[u]) {
            if (matchR[v] == -1 || dfs(matchR[v])) {
                matchR[v] = u;
                return true;
            }
        }
        return false;
    }

    void match() {
        shuffle(edges.begin(), edges.end(), rng);
        for(pair<int, int> edge: edges) {
            adj[edge.first].push_back(edge.second);
        }
        bool flag = 1;

        while(flag) {
            flag = 0;
            ++turn;
            for(int u = 0; u < n; ++u) {
                if (matchL[u])
                    continue;
                if (dfs(u)) {
                    flag = matchL[u] = true;
                    ++matched;
                }
            }
        }
    }

    vector< pair<int, int> > get_edges() {
        vector< pair<int, int> > res;
        for(int v = 0; v < m; ++v) {
            if (matchR[v] != -1) {
                res.push_back({matchR[v], v});
            }
        }
        return res;
    }
};