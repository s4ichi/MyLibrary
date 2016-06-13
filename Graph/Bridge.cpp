// test: uva 610

/*
  0-origin
*/

template<int V>
struct Bridge {
	int low[V], pre[V], cnt;
	vector<int> edge[V];
	bool res[V][V];

	void init() {
		cnt = 0;
		memset(low, 0, sizeof(low));
		memset(pre, 0, sizeof(pre));
		memset(res, false, sizeof(res));
		for (int i=0; i<V; i++) edge[i].clear();
	}

	void add_edge(int from, int to) {
		edge[from].push_back(to);
	}

	void add_edge_multi(int from, int to) {
		add_edge(from, to);
		add_edge(to, from);
	}

	int dfs(int cur, int from) {
		low[cur] = pre[cur] = ++cnt;

		for (int i=0; i<edge[cur].size(); i++) {
			int to = edge[cur][i];

			if (!pre[to]) {
				low[cur] = min(low[cur], dfs(to, cur));

				if (pre[to] == low[to]) {
					res[cur][to] = true;
				}
			} else if (from != to) {
				low[cur] = min(low[cur], low[to]);
			}
		}

		return low[cur];
	}

	void build(int n) {
		for (int i=0; i<n; i++) {
			if (!pre[i]) dfs(i, i);
		}
	}
};
