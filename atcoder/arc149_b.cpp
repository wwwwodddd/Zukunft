#include <bits/stdc++.h>
using namespace std;
int n, x;
pair<int, int> a[300020];
int f[300020];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
	}
	memset(f, 0x3f, sizeof f);
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		*upper_bound(f, f + n, a[i].second) = a[i].second;
	}
	cout << (lower_bound(f, f + n, 0x3f3f3f3f) - f) + n << endl;
	return 0;
}