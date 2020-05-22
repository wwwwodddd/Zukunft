#include <bits/stdc++.h>
using namespace std;
int n;
long long s[200020], z = 1e18;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		s[i] += s[i - 1];
	}
	for (int l = 0, r = 1, i = 1; i <= n; i++) {
		while (l < i && abs(s[i] - 2 * s[l]) > abs(s[i] - 2 * s[l + 1])) {
			l++;
		}
		while (r < n && abs(s[n] + s[i] - 2 * s[r]) > abs(s[n] + s[i] - 2 * s[r + 1])) {
			r++;
		}
		long long a[] = {s[l], s[i] - s[l], s[r] - s[i], s[n] - s[r]};
		sort(a, a + 4);
		z = min(z, a[3] - a[0]);
	}
	printf("%lld\n", z);
	return 0;
}