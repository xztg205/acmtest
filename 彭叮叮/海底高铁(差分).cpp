#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 10;
int n, m;
int p[N],a[N],b[N],c[N],diff[N];

void solve() {
	//洛谷P3406 海底高铁(差分)
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> p[i];
	for (int i = 1; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	ll ans = 0;
	for (int i = 1; i < m;i++) {
		int s = min(p[i], p[i + 1]);
		int e = max(p[i], p[i + 1]);
		diff[s]++; diff[e]--;
		//城市s->e 路s->e-1  
	}
	ll cnt = 0;//用于前缀和计数
	for (int i = 1; i < n; i++) {
		cnt += diff[i]; //这段路走了多少次
		ans += min(a[i] * cnt, b[i] * cnt + c[i]);
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
