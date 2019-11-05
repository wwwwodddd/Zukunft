#include <bits/stdc++.h>
using namespace std;
int main() {
	int n = 1000000000;
	long long ans = (long long)n * (n + 1) * 2 + 1 - (n - 1);
	ans -= (long long)(n + 1) * (n / 4) + (long long)n * (n / 4 + 1);
	long long d = 2LL * (n / 8) * (n / 8);
	long long x = 0;
	long long y = sqrt(d);
	while (x * x < d) {
		while (x * x + y * y >= d) {
			y--;
		}
		ans += 4 * y;
		x++;
	}
	cout << ans << endl;
	return 0;
}
