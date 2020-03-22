#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool v[22][22][22];
int f[22][22][22];
ll w(ll a, ll b, ll c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20); 
	}
	if (!v[a][b][c]) {
		v[a][b][c] = true;
		if (a < b && b < c) {
			f[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
		} else {
			f[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
		}
	}
	return f[a][b][c];
}
int main() {
	while (true) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
	}
	return 0;
}