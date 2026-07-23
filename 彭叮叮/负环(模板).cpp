#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;//权值 后继节点
const int MAXW = 1e9;
const int N = 2e3 + 10;
int n, m;
int dist[N],cnt[N];
bool inq[N];
vector<pii>g[N];

bool spfa() {
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		dist[i] = MAXW;
		inq[i] = 0;
		cnt[i] = 0;
	}
	dist[1] = 0;
	q.push(1);
	inq[1] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = 0;
		for (auto& it : g[u]) {
			int w = it.first;
			int v = it.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				if (!inq[v]) {
					cnt[v] = cnt[u] + 1;
					if (cnt[v] >= n) return 1;
					q.push(v);
					inq[v] = 1;
				}
			}
		}
	}
	return 0;
}

void solve() {
	//洛谷P3385 负环(模板)
	cin >> n >> m;
	for (int i = 1; i <= n; i++) g[i].clear();
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		if (w >= 0) {
			g[u].emplace_back(w, v);
			g[v].emplace_back(w, u);
		}
		else g[u].emplace_back(w, v);
	}
	if (spfa()) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; cin >> T;
	while (T--) solve();
	return 0;
}
