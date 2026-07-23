#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;//权值 后继节点
const int MAXW = 1e9;
const int N = 1e2 + 10;
int n, m;
int dist[N][N];

void solve() {
	//洛谷B3647 Floyd(模板)
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
		for (int j = i + 1; j <= n; j++) {
			dist[i][j] = MAXW;
			dist[j][i] = MAXW;
		}
	}//初始化dist
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = min(dist[u][v], w);
		dist[v][u] = min(dist[v][u], w);
	}
	//Floyd三重循环
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; 
	while (T--) solve();
	return 0;
}
