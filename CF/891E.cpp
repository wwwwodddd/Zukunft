#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[5020], x, p = 1000000007;
ll pw(ll x, ll y) {
	ll re = 1;
	for (; y > 0;) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}

int n;
int main() {
	cin >> n;
	f[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> x;
		for (int j = i; j >= 0; j--) {
			f[i + 1] = (f[i + 1] + f[i] * x) % p;
		}
	}
	for (int i = 0; i <= n; i++) {
		
	}

}