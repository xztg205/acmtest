#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;//权值 后继节点
const int MAXINT = 0x7fffffff;
const int N = 1e5 + 10;
vector<pii>g[N];
ll dist[N];
int n, m, s;

void dijkstra() {
	for (int i = 1; i <= n; i++) dist[i] = MAXINT;
	dist[s] = 0; //初始化dist
	priority_queue<pii, vector<pii>, greater<pii>> heap;
	heap.push({ 0,s });
	while (!heap.empty()) {
		ll d = heap.top().first;
		int u = heap.top().second;
		heap.pop();
		if (d > dist[u]) continue;
		//历史脏数据去除(更远的路不要处理)
		for (auto& it : g[u]) {
			ll w = it.first;
			int v = it.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				//选更近的路
				heap.push({ dist[v], v });
				//更新路径才入堆
			}
		}
	}
}

void solve() {
	//洛谷P4779 【模板】单源最短路径(标准版)
	cin >> n >> m >> s;
	while(m--) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		g[u].emplace_back(w, v);
	}
	dijkstra();
	for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; 
	while (T--) solve();
	return 0;
}
