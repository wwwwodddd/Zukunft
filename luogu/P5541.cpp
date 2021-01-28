#include <bits/stdc++.h>
using namespace std;
int n, a[100020];
int work() {
	if (a[n - 1] == a[0] + n - 1) {
		return 0;
	}
	if (a[n - 2] == a[0] + n - 2 || a[n - 1] == a[1] + n - 2) {
		if (a[n - 1] == a[0] + n) {
			return 1;
		} else {
			return 2;
		}
	}
	int z1 = n;
	for (int i = 0; i < n; i++) {
		int p = a[i] + n - 1;
		int t = upper_bound(a, a + n, p) - a;
		z1 = min(z1, n - (t - i));
	}
	for (int i = 0; i < n; i++) {
		int p = a[i] - n + 1;
		int t = lower_bound(a, a + n, p) - a - 1;
		z1 = min(z1, n - (i - t));
	}
	return z1;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int z2 = max(a[n - 1] - a[1], a[n - 2] - a[0]) - n + 2;
	cout << work() << endl;
	cout << z2 << endl;
	return 0;
}