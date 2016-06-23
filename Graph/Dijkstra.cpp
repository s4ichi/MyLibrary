const int N = 1500;
int adj[N][N];
const int UNCONNECTED = -1;

struct Node {
	int n;
	int w;
	Node(int _n, int _w) : n(_n), w(_w) {}
	bool operator<(const Node &nd) const {
		return w > nd.w;
	}
};

int dijkstra(const int s, const int t, vector<int> &path, const int n)
{
	int cost[N];
	//int parent[N]; // path
	bool visit[N] = { 0 };

	fill(cost, cost + N, INT_MAX);
	fill(parent, parent + N, -1);

	priority_queue<Node> node;

	node.push(Node(s, 0));
	cost[s] = 0;

	int dist = INT_MAX;
	while (!node.empty()) {

		Node now = node.top();
		node.pop();

		if (visit[now.n]) continue;

		visit[now.n] = true;

		if (now.n == t) {
			dist = now.w;
			break;
		}

		for (int i=0; i<n; i++) {
			if (visit[i]) continue;
			if (adj[now.n][i]==UNCONNECTED) continue;

			int now_cost = now.w+adj[now.n][i];

			if (cost[i] > now_cost) {
				parent[i] = now.n;
				cost[i] = now_cost;
				node.push(Node(i, now_cost));
			}
		}
	}

	if (dist == INT_MAX) return -1;

	/*
	int v = t;
	while (v!=-1) {
		path.push_back(v);
		v = parent[v];
	}
	reverse(path.begin(), path.end());
	*/

	return dist;
}
