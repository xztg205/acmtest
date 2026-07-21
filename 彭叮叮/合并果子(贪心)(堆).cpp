#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 1e4 + 100;
int n;
priority_queue<int,vector<int>,greater<int>>heap; //小根堆
//priority_queue<int>heap; //大根堆

void solve() {
	//洛谷P1090 合并果子(贪心)(堆)
	cin >> n;
	for (int i = 1; i <= n; i++) { 
		int x;
		cin >> x;
		heap.push(x);
	}
	int ans = 0;
	while (heap.size()>1) {
		int a = heap.top();
		heap.pop();
		int b = heap.top();
		heap.pop();
		ans += a + b;
		heap.push(a + b);
	}//直至剩下一个堆
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	while (T--) solve();
	return 0;
}
