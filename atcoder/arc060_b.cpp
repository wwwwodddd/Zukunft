#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll F(ll n, ll b) {
	ll re = 0;
	while (n > 0) {
		re += n % b;
		n /= b;
	}
	return re;
}

int main() {
	ll n, s, i;
	cin >> n >> s;
	if (n == s) {
		printf("%lld\n", n + 1);
		return 0;
	}
	for (i = 2; i * i <= n; i++) {
		if (F(n, i) == s) {
			printf("%lld\n", i);
			return 0;
		}
	}
	for (; i >= 1; i--) {
		if ((n - s) / i >= 1 && F(n, (n - s) / i + 1) == s) {
			printf("%lld\n", (n - s) / i + 1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}