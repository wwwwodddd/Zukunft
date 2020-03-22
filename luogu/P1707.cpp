#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, mod;
ll mul(ll x, ll y)
{
	ll re = 0;
	for (; y > 0; y >>= 9)
	{
		re = (re + y % 512 * x) % mod;
		x = x * 512 % mod;
	}
	return re;
}
void mul(ll a[11][11], ll b[11][11]) {
	ll w[11][11] = {};
	for (int i = 0; i < 11; i++) {
		for (int k = 0; k < 11; k++) {
			if (a[i][k] == 0) {
				continue;
			}
			for (int j = 0; j < 11; j++) {
				w[i][j] = (w[i][j] + mul(a[i][k], b[k][j])) % mod;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int main() {
	int p, q, r, t, u, v, w, x, y, z;
	cin >> n >> mod;
	cin >> p >> q >> r >> t;
	cin >> u >> v >> w;
	cin >> x >> y >> z;
	ll a[11][11] = {
		{3,1,3,1,3,1,w,z,1,1,1}
	};
	ll b[11][11] = {
		{p,1,1,0,1,0,0,0,0,0,0},
		{q,0,0,0,0,0,0,0,0,0,0},
		{1,0,u,1,1,0,0,0,0,0,0},
		{0,0,v,0,0,0,0,0,0,0,0},
		{1,0,1,0,x,1,0,0,0,0,0},
		{0,0,0,0,y,0,0,0,0,0,0},
		{0,0,1,0,0,0,w,0,0,0,0},
		{0,0,0,0,1,0,0,z,0,0,0},
		{r,0,0,0,0,0,0,0,1,0,0},
		{t,0,0,0,1,0,0,0,2,1,0},
		{1,0,0,0,2,0,0,0,1,1,1}
	};
	for (n -= 2; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	printf("nodgd %lld\n", a[0][0]);
	printf("Ciocio %lld\n", a[0][2]);
	printf("Nicole %lld\n", a[0][4]);
	return 0;
}