#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, c[666][8], u[4], z;
ll F(ll a, ll b, ll c, ll d) {
	return a << 30 | b << 20 | c << 10 | d;
}
map<ll, ll> g;
void A(ll x, ll v) {
	for (int i = 0; i < 4; i++) {
		g[x] += v;
		x = (x >> 10) | (x & 1023) << 30;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> c[i][j];
			c[i][j + 4] = c[i][j];
		}
		A(F(c[i][0], c[i][1], c[i][2], c[i][3]), 1);
	}
	for (int i = 0; i < n; i++) {
		A(F(c[i][0], c[i][1], c[i][2], c[i][3]), -1);
		for (int j = i + 1; j < n; j++) {
			A(F(c[j][0], c[j][1], c[j][2], c[j][3]), -1);
			for (int k = 0; k < 4; k++) {
				ll r = 1;
				u[0] = F(c[j][k + 1], c[j][k + 0], c[i][1], c[i][0]);
				u[1] = F(c[j][k + 0], c[j][k + 3], c[i][2], c[i][1]);
				u[2] = F(c[j][k + 3], c[j][k + 2], c[i][3], c[i][2]);
				u[3] = F(c[j][k + 2], c[j][k + 1], c[i][4], c[i][3]);
				if (g[u[0]] && g[u[1]] && g[u[2]] && g[u[3]]) {
					r *= g[u[0]];
					A(u[0], -1);
					r *= g[u[1]];
					A(u[1], -1);
					r *= g[u[2]];
					A(u[2], -1);
					r *= g[u[3]];
					A(u[2], 1);
					A(u[1], 1);
					A(u[0], 1);
					z += r;
				}
			}
			A(F(c[j][0], c[j][1], c[j][2], c[j][3]), 1);
		}
	}
	cout << z << endl;
	return 0;
}