#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll F(ll n, int x) { // < n  contains how many x
	ll t = 1, z = 0;
	while (t < n) {
		z += n / 10 / t * t;
		if (n / t % 10 > x) {
			z += t;
		} else if (n / t % 10 == x) {
			z += n % t;
		}
		if (x == 0) {
			z -= t;
		}
		t *= 10;
	}
	return z;
}
ll a, b;
int main() {
	cin >> a >> b;
	for (int i = 0; i < 10; i++) {
		cout << F(b + 1, i) - F(a, i) << ' ';
	}
	return 0;
}