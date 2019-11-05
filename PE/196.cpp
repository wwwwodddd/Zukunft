#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v[50000020];
void pre(ll l, ll r) {
	for (ll i = 2; i * i <= r; i++) {
		for (ll j = (l + i - 1) / i * i; j <= r; j += i) {
			v[j - l] = i;
		}
	}
	for (ll i = l; i <= r; i++) {
		if (v[i - l] == i || v[i - l] == 0) {
			v[i - l] = 1;
		} else {
			v[i - l] = 0;
		}
	}
}
ll F(ll x) {
	return x * (x - 1) / 2;
}
int a[5][10000010];
int vis[5][10000010], cnt;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dfs(int x, int y) {
	if (x < 0 || x >= 5 || y < 0 || a[x][y] == 0 || vis[x][y] == cnt) {
		return 0;
	}
	vis[x][y] = cnt;
	int re = 1;
	for (int i = 0; i < 8; i++) {
		re += dfs(x + dx[i], y + dy[i]);
	}
	return re;
}
ll S(ll x) {
	ll L = F(x - 2) + 1, R = F(x + 3) + 1;
	cerr << L << ' ' << R << endl;
	pre(L, R);
	ll t = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < x + i - 2; j++) {
			a[i][j] = v[t++];
		}
	}
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < x + i - 2; j++) {
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
	t = F(x) + 1;
	ll z = 0;
	for (int i = 0; i < x; i++, t++) {
		cnt++;
		if (dfs(2, i) >= 3) {
			z += t;
//			cerr << t << endl;
		}
	}
	return z;
}

int main() {
	cout << S(10000) << endl;
	cout << S(5678027) + S(7208785) << endl;
	return 0;
}