#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
long long ans;
long long n, m;
int v[100];
long long gcd(long long x, long long y) {
	return y ? gcd(y, x % y) : x;
}
long long lcm(long long x, long long y) {
	return x / gcd(x, y) * y;
}
void dfs(int d, int x, long long y, int z) {
	if (y > d * m) {
		return;
	}
	ans += z * (d * m / y - (d - 1) * m / y);
	for (; x >= d; x--) {
		if (v[x] == 0) {
			if (x / gcd(x, y) > d * m / y) {
				continue;
			}
			dfs(d, x - 1, lcm(x, y), -z);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		memset(v, 0, sizeof v);
		for (int j = i; j <= n; j++) {
			for (int k = j + j; k <= n; k += j) {
				v[k] = 1;
			}
		}
		int cnt = 0;
		for (int j = i; j <= n; j++) {
			if (v[j] == 0) {
//				cout << "..." << j << endl;
				cnt++;
			}
		}
		cout << cnt << endl;
		dfs(i, n, 1, 1);
		cout << ans << endl;
	}
	printf("%lld\n", n * m - ans);
	return 0;
}