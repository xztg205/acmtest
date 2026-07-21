#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N = 1e6+10; //x y 范围是小于5000
int n, m;
int r[N];
ll di[N];

struct{
	int s, t;
	ll d; //参与加法的大数用ll
}order[N];


bool check(int x) {
	memset(di, 0, sizeof(di)); //清零
	for (int i = 1; i <= x; i++) {
		int d = order[i].d, s = order[i].s, t = order[i].t;
		di[s] -= d;
		di[t + 1] += d;
		//临时差分 表示每天需要消耗的房间数的差分
	}
	ll now = 0; 
	// 一个负数 来累计差分数组的前n项和 累积到哪一天就是算到哪一天需要消耗的房间数
	for (int i = 1; i <= n; i++) {
		now += di[i];
		if (r[i] + now < 0) return 0;
	}
	return 1;
}

void solve() {
	//洛谷P1083 借教室(差分+二分)
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> order[i].d >> order[i].s >> order[i].t;
	}
	int ans = 0;
	int l = 1, r = m;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (!check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (ans) cout << -1 << '\n' << ans;
	else cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; 
	while (T--) solve();
	return 0;
}
