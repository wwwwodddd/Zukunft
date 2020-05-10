#include <bits/stdc++.h>
using namespace std;
int n, x;
int w[400];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		w[i] *= 2;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			scanf("%d", &x);
			w[i] += x;
			w[j] += x;
		}
	}
	sort(w + 1, w + n + 1);
	reverse(w + 1, w + n + 1);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			ans += w[i];
		} else {
			ans -= w[i];
		}
	}
	ans /= 2;
	printf("%lld\n", ans);
	return 0;
}