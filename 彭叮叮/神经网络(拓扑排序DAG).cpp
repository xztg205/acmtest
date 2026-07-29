#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const int N = 1e2 + 10;
int n, p, U[N], in[N];
ll C[N];
vector<pii>g[N];

void solve() {
	//洛谷P1038 神经网络(拓扑排序DAG)
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		cin >> C[i] >> U[i];
	}
	for (int i = 1; i <= p; i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		g[u].emplace_back(w, v);
		in[v]++;
	}
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (!in[i]) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto& it : g[u]) {
			ll w = it.first;
			int v = it.second;
			if(C[u]>0) C[v] += w * C[u];
			//兴奋的神经元才会传送信号
			in[v]--;
			if (!in[v]) {
				C[v] -= U[v];
				//输入层无需使用公式无需自减 状态由题目自行给出
				q.push(v);
			}
		}
	}
	bool ans = 1;
	for (int i = 1; i <= n; i++) {
		if (g[i].empty()&&C[i] > 0) {
			cout << i << ' ' << C[i] << '\n';
			ans = 0;
		}
	}
	if(ans) cout<<"NULL";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	while (T--) solve();
	return 0;
}
