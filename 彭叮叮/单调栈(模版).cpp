#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 3e6+10; 
int n;
int a[N],ans[N];
stack<int> st; //存离目前元素后面更近的下标

void solve() {
	//洛谷P5788 单调栈(模版)
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && a[st.top()] <= a[i]) st.pop(); 
		//将栈自顶向下淘汰小于目前元素的数 
		//此题精髓是要找目前元素后面的 离它最近的且>=它的
		// a b c 若c<b 那么找a的时候 b的优先级更大 因为b离a更近且b>c 
		if (st.empty()) ans[i] = 0;
		else ans[i] = st.top();
		//你没有被淘汰 就决定是你了 你被邀请了
		st.push(i);
		//目前元素下标入栈
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; 
	while (T--) solve();
	return 0;
}
