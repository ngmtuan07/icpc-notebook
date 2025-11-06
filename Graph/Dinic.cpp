// Worst-case time complexity: O(V^2 * E)
// Unit-capacity networks (all capacities = 1): O(min(V^{2/3}, sqrt(E)) * E).
// Bipartite matching (as a special case): O(sqrt(V) * E).
// (often near O(E * sqrt(V)) or O(E * V) in practice depending on structure).
#define int long long
const int inf = 1e18;
struct dinic {
  struct edge {
    int v, oth, fl, cap;
  };
  vector<vector<edge> > adj;
  vector<int> ptr, lv;
  dinic() {}
  int st, en;
  dinic(int n) {
    st = n + 1;
    en = n + 2;
    adj.assign(n + 7, vector<edge>());
    ptr.assign(n + 7, 0);
    lv.assign(n + 7, 0);
  }
  void add(int u, int v, int cap, int undirected = 0) {
    adj[u].push_back({v, (int)adj[v].size(), 0, cap});
    adj[v].push_back({u, (int)adj[u].size() - 1, 0, undirected * cap});
  }
  bool bfs() {
    fill(lv.begin(), lv.end(), -1);
    lv[st] = 0;
    queue<int> q;
    q.push(st);
    while (q.size() && lv[en] == -1) {
      int u = q.front();
      q.pop();
      for (edge& x : adj[u]) {
        if (lv[x.v] == -1 && x.cap > x.fl) {
          q.push(x.v);
          lv[x.v] = lv[u] + 1;
        }
      }
    }
    return lv[en] != -1;
  }
  int dfs(int u, int flowin) {
    if (u == en) return flowin;
    int flout = 0;
    for (; ptr[u] < (int)adj[u].size(); ptr[u]++) {
      edge& x = adj[u][ptr[u]];
      if (x.cap > x.fl && lv[x.v] == lv[u] + 1) {
        int tmp = dfs(x.v, min(flowin, x.cap - x.fl));
        x.fl += tmp;
        adj[x.v][x.oth].fl -= tmp;
        flout += tmp;
        flowin -= tmp;
        if (flowin == 0) break;
      }
    }
    return flout;
  }
  int max_flow() {
    int res = 0;
    while (bfs()) {
      fill(ptr.begin(), ptr.end(), 0);
      res += dfs(st, inf);
    }
    return res;
  }
};