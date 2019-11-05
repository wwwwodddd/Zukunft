#include <bits/stdc++.h>
using namespace std;
long long f[10000020];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		int j = i - (i - 1) / 2;
		long long a = (long long)(i - 1) * (i - 2) / 2 - 3 * (long long)(j - 1) * (j - 2) / 2;
		long long b = (i - 1) / 2 - i / 2 / 2;
		long long c = i % 3 == 0;
		f[i] = (a - 3 * b + 2 * c) / 6 + b;
//		cerr << a << ' ' << b << ' ' << c << endl;
		cerr << i << ' ' << f[i] << endl;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + i; j <= n; j += i) {
			f[j] -= f[i];
		}
		ans += f[i];
	}
	cout << ans << endl;
	return 0;
}
