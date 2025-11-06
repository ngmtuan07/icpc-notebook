pair<bool, vector<int>> topo_sort(const vector<vector<int>>& g) {
  int n = g.size();
  // init in_deg
  vector<int> in_deg(n, 0);
  for (int u = 0; u < n; u++) {
    for (int v : g[u]) {
      in_deg[v]++;
    }
  }

  // find topo order
  vector<int> res;
  queue<int> qu;
  for (int u = 0; u < n; u++) {
    if (in_deg[u] == 0) {
      qu.push(u);
    }
  }

  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();
    res.push_back(u);
    for (int v : g[u]) {
      in_deg[v]--;
      if (in_deg[v] == 0) {
        qu.push(v);
      }
    }
  }

  if ((int)res.size() < n) {
    return {false, {}};
  }
  return {true, res};
}