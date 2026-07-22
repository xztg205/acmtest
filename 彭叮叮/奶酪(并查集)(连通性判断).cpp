#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e3 + 10;
int n, f[N];
ll h, r;

struct nihao{
	ll x, y, z;
}hole[N];

int findF(int x) {
	return f[x] == x ? x : f[x] = findF(f[x]);
}

void mergeF(int a, int b) {
	a = findF(a);
	b = findF(b);
	f[a] = b;
}

ll distpow(nihao a,nihao b) {
	//两点之间直线距离公式
	//此处返回距离的平方 避免丢失精度
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	ll dz = a.z - b.z;
	return dx * dx + dy * dy + dz * dz;
}

void solve() {
	//洛谷P3958 奶酪(并查集)(连通性判断)
	cin >> n >> h >> r;
	for (int i = 1; i <= n; i++) {
		cin >> hole[i].x >> hole[i].y >> hole[i].z;
		f[i] = i;//初始化
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (distpow(hole[i],hole[j])<=(r*2)*(r*2)) mergeF(i,j);
			//平方比较 避免丢失精度
		}
	}
	for (int i = 1; i <= n; i++) {
		if (hole[i].z - r <= 0) {//找下面联通
			for (int j = 1; j <= n; j++) {
				if (hole[j].z + r >= h) {//找上面联通
					if (findF(i) == findF(j)) {//联通的两个洞是否联通(属于一个集)
						cout << "Yes\n";
						return;
					}
				}
			}
		}
	}
	cout << "No\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; cin >> T;
	while (T--) solve();
	return 0;
}
