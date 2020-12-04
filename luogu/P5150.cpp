#include <bits/stdc++.h>
using namespace std;
long long n, ans = 1;
int main() {
	cin >> n;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
			ans *= 2 * cnt + 1;
		}
	}
	if (n > 1) {
		ans *= 3;
	}
	cout << ans << endl;
	return 0;
}