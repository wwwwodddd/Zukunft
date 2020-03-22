#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[200020];
int f[200020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++) {
		*upper_bound(f, f + n, a[i].second) = a[i].second;
	}
	cout << (lower_bound(f, f + n, 0x3f3f3f3f) - f) << endl;
	return 0;
}