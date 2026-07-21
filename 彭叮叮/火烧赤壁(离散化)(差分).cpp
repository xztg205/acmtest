#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5+10; 
int n;
pii a[N];

void solve() {
  //洛谷P1496 火烧赤壁(离散化)(差分)
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + n + 1);
	int s = a[1].first, e = a[1].second;
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i].first <= e) {
			e = max(e, a[i].second);
		}
		else {
			ans += e - s;
			s = a[i].first;
			e = a[i].second;
		}
	}
	ans += e - s;
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; 
	while (T--) solve();
	return 0;
}
