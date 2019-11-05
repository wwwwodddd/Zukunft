#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[50000020];
int f[50000020];
int F(int n) {
	int two = 1;
	int three = 1;
	for (int i = 0; i <= 2 * n; i++) {
		a[i] = make_pair(two % n, three % n);
		two = two * 2 % n;
		three = three * 3 % n;
	}
	n = 2 * n + 1;
	sort(a, a + n);
	n = unique(a, a + n) - a;
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++) {
		*upper_bound(f, f + n, a[i].second) = a[i].second;
	}
	return lower_bound(f, f + n, 0x3f3f3f3f) - f;
}
int main() {
	int ans = 0;
	cout << F(123) << endl;
	cout << F(10000) << endl;
	for (int i = 1; i <= 30; i++) {
		cout << i << endl;
		ans += F(i * i * i * i * i);
	}
	cout << ans << endl;
	return 0;
}