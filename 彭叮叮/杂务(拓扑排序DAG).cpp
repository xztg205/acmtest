#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e4 + 10;
int n, ans;
int cost[N],in[N],dp[N];
vector<int>g[N]; //邻接表 存后继结点


void solve() {
  //洛谷P1113 杂务(拓扑排序DAG)
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> i >> cost[i];
		dp[i] = cost[i];
		int work;
		while (1) {
			cin >> work;
			if (!work) break;
			g[work].push_back(i);
			in[i]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!in[i]) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		ans = max(ans, dp[u]);
		for (auto& v : g[u]) {
			dp[v] = max(dp[v], dp[u] + cost[v]);
			in[v]--;
			if (!in[v]) q.push(v);
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	while (T--) solve();
	return 0;
}
