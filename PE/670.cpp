#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 1e16;
ll p = 1000004321;
ll a[7][7];
ll b[7][7];
void mul(ll a[7][7], ll b[7][7]) {
	ll c[7][7] = {};
	for (int i = 0; i < 7; i++) {
		for (int k = 0; k < 7; k++) {
			if (a[i][k] == 0) {
				continue;
			}
			for (int j = 0; j < 7; j++) {
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, c, sizeof c);
}
int main() {
	a[0][0] = 4;
	a[0][1] = 12;
	b[0][0] = 3;
	b[0][1] = 6;
	b[1][0] = 2;
	b[1][2] = 2;
	b[1][4] = 1;
	b[2][0] = 4;
	b[2][2] = 2;
	b[2][3] = 2;
	b[2][5] = 1;
	b[3][0] = 4;
	b[3][2] = 2;
	b[4][0] = 2;
	b[4][3] = 2;
	b[4][6] = 1;
	b[5][0] = 4;
	b[5][3] = 2;
	b[6][0] = 2;
	for (n-- ; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	ll ans = (a[0][0] + a[0][1] + a[0][2] * 2 + a[0][3] * 2 + a[0][4] + a[0][5] * 2 + a[0][6]) % p;
	printf("%d\n", (int)ans);
	return 0;
}