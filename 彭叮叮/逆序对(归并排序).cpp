#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 10;
int n;
ll ans;
int a[N], t[N];

void msort(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	int i = l, j = mid + 1;//两块的起始点
	msort(l, mid);
	msort(mid + 1, r);
	int k = l;//遍历临时数组的索引;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) t[k++] = a[i++];
		else {
			t[k++] = a[j++];
			ans += mid - i + 1;
		}
	}
	while (i <= mid) t[k++] = a[i++];
	while (j <= r) t[k++] = a[j++];
	for (; l <= r; l++) a[l] = t[l];
}

void solve() {
    //洛谷P1908 逆序对(归并排序)
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	msort(1, n);
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	while (T--) solve();
	return 0;
}
