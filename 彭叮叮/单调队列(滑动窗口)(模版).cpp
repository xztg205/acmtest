#include<iostream>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6+10; 
int n, k;
int a[N],minA[N], maxA[N];
deque<int> minn;//存下标 单调递增区间 队头为区间内最小值的下标
deque<int> maxx;//存下标 单调递减区间 队头为区间内最大值的下标

void solve() {
	//洛谷P1886 单调队列(滑动窗口)(模版)
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		while (!minn.empty() && a[minn.back()] >= a[i]) minn.pop_back(); 
		minn.push_back(i);
		if (minn.front() < i - k + 1) minn.pop_front();
		minA[i] = a[minn.front()];
	}
	for (int i = 1; i <= n; i++) {
		while (!maxx.empty() && a[maxx.back()] <= a[i]) maxx.pop_back();
		maxx.push_back(i);
		if (maxx.front() < i - k + 1) maxx.pop_front();
		maxA[i] = a[maxx.front()];
	}
	for (int i = k; i <= n; i++) cout << minA[i] << ' ';
	cout << '\n';
	for (int i = k; i <= n; i++) cout << maxA[i] << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; 
	while (T--) solve();
	return 0;
}
