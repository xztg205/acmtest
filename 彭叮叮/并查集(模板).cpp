#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6+10; 
int n, m, f[N], sz[N];

void init() {
	for (int i = 1; i <= n; i++) {
		f[i] = i;
		sz[i] = 1;
	}
}

int findF(int x) {
	return f[x] == x ? x : f[x] = findF(f[x]);
}

void mergeF(int a, int b) {
	a = findF(a);
	b = findF(b);
	if (sz[a] > sz[b]) {
		int t = a;
		a = b;
		b = t;
	}
	f[a] = b;
	sz[b] += sz[a];
}

void solve() {
  //洛谷P3367 【模板】并查集
	cin >> n >> m;
	init();
	while (m--) {
		int z, x, y;
		cin >> z >> x >> y;
		if (z == 1) {
			mergeF(x, y);
		}
		else if (z == 2) {
			if (findF(x) == findF(y)) cout << "Y\n";
			else cout << "N\n";
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
