#include <bits/stdc++.h>
using namespace std;
int n, a[999];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n + 1);
	long long ans = 0;
	for (int i = 0, j = n; i < j;) {
		ans += (a[i] - a[j]) * (a[i] - a[j]);
		i++;
		ans += (a[i] - a[j]) * (a[i] - a[j]);
		j--;
	}
	printf("%lld\n", ans);
	return 0;
}