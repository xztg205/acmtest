#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e3 + 10;
int n, m, e;
vector<int>g[N];//左结点能连哪些右结点
int match[N];//右结点配的是哪个左结点
bool vis[N];//是否访问过右结点

bool dfs(int u) {
	for (auto& v : g[u]) {
		if (!vis[v]) {//防止自己和自己打起来
			vis[v] = 1;
			if (!match[v] || dfs(match[v])) {
				//右结点没匹配或者右结点匹配的左结点换点成功
				match[v]=u;
				return 1;
				//u找好节点了可以返回了
			}
		}
	}
	return 0;
}

void solve() {
	//洛谷P3386 二分图最大匹配(模版)(匈牙利)
	cin >> n >> m >> e;
	while (e--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) ans++;
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
