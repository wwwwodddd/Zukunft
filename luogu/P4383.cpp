#include <bits/stdc++.h>
using namespace std;
int n, k, M;
vector<pair<int, int> > a[300020];
typedef long long ll;
struct D {
	ll x, y;
	D(ll x = 0, ll y = 0): x(x), y(y) {
	}
}f[300020][3];
D operator+(const D &a, const D &b) {
	return D(a.x + b.x, a.y + b.y);
}
D operator+(const D &a, int x) {
	return D(a.x + x, a.y);
}
bool operator<(const D &a, const D &b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.y > b.y;
}
D dec(D a) {
	return D(a.x + M, a.y + 1);
}
void dfs(int x, int y) {
	f[x][0] = D(0, 0);
	f[x][1] = D(0, 0);
	f[x][2] = D(0, 0);
	for (pair<int, int> i: a[x]) {
		if (i.first == y) {
			continue;
		}
		dfs(i.first, x);
		f[x][2] = max(f[x][2] + f[i.first][2], dec(f[x][1] + f[i.first][1] + i.second));
		f[x][1] = max(f[x][1] + f[i.first][2], f[x][0] + f[i.first][1] + i.second);
		f[x][0] = f[x][0] + f[i.first][0];
	}
	f[x][2] = max(f[x][2], f[x][0]);
	f[x][2] = max(f[x][2], dec(f[x][1]));
}
int main() {
	scanf("%d%d", &n, &k);
	k++;
	for (int i = 1; i < n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	int R = 1000001, L = -R;
	while (L < R - 1) {
		M = (L + R) / 2;
		dfs(1, 0);
		if (f[1][2].y > k) {
			R = M;
		} else {
			L = M;
		}
	}
	M = L;
	dfs(1, 0);
	printf("%lld\n", f[1][2].x - k * M);
	return 0;
}