#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 3e4 + 10;
int t, f[N], sz[N], dis[N];

void init() {
	for (int i = 1; i < N; i++) {//注意不要让数组越界
		f[i] = i;
		sz[i] = 1; //存放整棵树的元素数量
		dis[i] = 0; //存放自己到祖先的距离
	}
}

int findF(int x) {
	if (f[x] != x) {
		int root = findF(f[x]);
		dis[x] += dis[f[x]];
		//先知道和爷爷之间还有个爸爸 把自己栓到爷爷身上
		//先加上父节点到祖宗之间的距离 把自己栓到祖宗身上
		f[x] = root;
	}
	return f[x];
}

void mergeF(int a, int b) {
	a = findF(a);
	b = findF(b);
	f[a] = b;
	dis[a] = sz[b];
	//a树的根到b树的根的距离为b树元素数量
	//a树内部元素的距离会在findF状压时更新
	sz[b] += sz[a];
	//由于合并 b树元素数量加上了a组元素数量
}

void solve() {
	//洛谷P1196 银河英雄传说(带权并查集)
	cin >> t;
	init();
	while (t--) {
		char z;
		int i,j;
		cin >> z >> i >> j;
		if (z == 'M') {
			mergeF(i, j);
		}
		else if (z == 'C') {
			if (findF(i) == findF(j)) cout <<abs(dis[i]-dis[j])-1 << "\n";
			else cout << "-1\n";
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
