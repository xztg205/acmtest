#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 10;
int n, k, cntEdge, sumW;
int f[N];

void init() {
	for (int i = 1; i <= n; i++) f[i] = i;
}

int findF(int x) {
	return f[x] == x ? x : f[x] = findF(f[x]);
}

struct Edge{
	int u, v, w;
};
vector<Edge>edge;

bool cmp(Edge& a, Edge& b) {
	return a.w < b.w;
}

void solve() {
	//洛谷P2820 局域网(MST)
	cin >> n >> k;
	init();
	while (k--) {
		int i, j, m;
		cin >> i >> j >> m;
		edge.push_back({ i, j, m });
		sumW += m;
	}
	sort(edge.begin(), edge.end(), cmp);
	for (auto& e : edge) {
		int u = e.u, v = e.v, w = e.w;
		int fu = findF(u), fv = findF(v);
		if (fu != fv) { //不在一个集合里才加入最小生成树 避免环
			f[fu] = fv;
			sumW -= w; //减去加入的权值 题目要求剩余的权值和
			cntEdge++;
			if (cntEdge == n - 1) {
				cout << sumW;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	while (T--) solve();
	return 0;
}
