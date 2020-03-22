#include <bits/stdc++.h>
using namespace std;
int n, k, p = 100003;
int f[100020];
int main() {
	f[0] = f[1] = 1;
	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		f[i] = 2 * f[i - 1];
		if (i >= k + 1) {
			f[i] += p - f[i - k - 1];
		}
		f[i] %= p;
	}
	cout << f[n] << endl;
	return 0;
}