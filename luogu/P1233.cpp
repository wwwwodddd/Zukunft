#include <bits/stdc++.h>
using namespace std;
int n;
int f[100020];
pair<int, int> a[100020];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++) {
		a[i].second = -a[i].second;
		*lower_bound(f, f + n, a[i].second) = a[i].second;
	}
	cout << (lower_bound(f, f + n, 0x3f3f3f3f) - f) << endl;
	return 0;
}