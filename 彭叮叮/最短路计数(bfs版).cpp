#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 10;
const int MOD = 1e5 + 3;
int n, m;
int dist[N], cnt[N];
vector<int>g[N];

void solve() {
	//洛谷P1144 最短路计数(bfs版)
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) dist[i] = -1;
	queue<int>q;
	q.push(1);
	cnt[1] = 1;
	dist[1] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto& v : g[u]) {
			if (u == v) continue;
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				cnt[v] = cnt[u] % MOD;
				//同一条路 最短路径继承
				q.push(v);
			}
			else if (dist[v] == dist[u] + 1) {
				//新路径 新旧相加
				cnt[v] = (cnt[v] + cnt[u]) % MOD;
			}
			
		}
	}
	for (int i = 1; i <= n; i++) cout << cnt[i] << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	while (T--) solve();
	return 0;
}
