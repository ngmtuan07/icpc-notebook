struct EulerUndirected {
  EulerUndirected(int _n) : n(_n), m(0), adj(_n), deg(_n, 0) {}
  void add_edge(int u, int v) {
    adj[u].push_front(Edge(v));
    auto it1 = adj[u].begin();
    adj[v].push_front(Edge(u));
    auto it2 = adj[v].begin();

    it1->rev = it2;
    it2->rev = it1;

    ++deg[u];
    ++deg[v];
    ++m;
  }
  pair<bool, vector<int>> solve() {
    int cntOdd = 0;
    int start = -1;
    for (int i = 0; i < n; i++) {
      if (deg[i] % 2) {
        ++cntOdd;
        if (cntOdd > 2) return {false, {}};

        if (start < 0) start = i;
      }
    }
    // no odd vertex -> start from any vertex with positive degree
    if (start < 0) {
      for (int i = 0; i < n; i++) {
        if (deg[i]) {
          start = i;
          break;
        }
      }
      if (start < 0) {
        // no edge -> empty path
        return {true, {}};
      }
    }

    vector<int> path;
    find_path(start, path);

    if (m + 1 != static_cast<int>(path.size())) {
      return {false, {}};
    }

    return {true, path};
  }
  struct Edge {
    int to;
    list<Edge>::iterator rev;

    Edge(int _to) : to(_to) {}
  };
  // private:
  int n, m;
  vector<list<Edge>> adj;
  vector<int> deg;

  void find_path(int v, vector<int>& path) {
    while (adj[v].size() > 0) {
      int next = adj[v].front().to;
      adj[next].erase(adj[v].front().rev);
      adj[v].pop_front();
      find_path(next, path);
    }
    path.push_back(v);
  }
};