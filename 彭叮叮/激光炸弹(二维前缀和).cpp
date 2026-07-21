#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 5005; //x y 范围是小于5000
int n, m;
int p[N][N];

void solve() {
	//洛谷P2280 激光炸弹(二维前缀和)
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x, y, v;
		cin >> x >> y >> v;
		p[x+1][y+1] += v; //调整成base-1
	}
	for (int i = 1; i <= 5001; i++) { //注意这里不能写i<=N 数组毕竟默认base-0
		for (int j = 1; j <= 5001; j++) {
			p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
		}
	}
	int ans = 0;
	for (int i = m; i <= 5001; i++) {
		for (int j = m; j <= 5001; j++) {
			ans = max(ans, p[i][j] - p[i - m][j] - p[i][j - m] + p[i - m][j - m]);
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
