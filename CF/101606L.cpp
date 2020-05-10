#include <bits/stdc++.h>
using namespace std;
int n, X, Y, ans;
int f[1000020];
pair<pair<int, int>, pair<int, int> > a[1000020];
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int main() {
	scanf("%d%d", &X, &Y);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a[i].first.first, &a[i].first.second, &a[i].second.second);
		a[i].first.first -= X;
		a[i].first.second -= Y;
		int g = abs(gcd(a[i].first.first, a[i].first.second));
		a[i].first.first /= g;
		a[i].first.second /= g;
		a[i].second.first = g;
	}
	sort(a, a + n);
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++) {
		if (i == 0 || a[i].first != a[i - 1].first) {
			for (int j = 0; j < n; j++) {
				if (f[j] == 0x3f3f3f3f) {
					break;
				}
				f[j] = 0x3f3f3f3f;
				ans++;
			}
		}
		*lower_bound(f, f + n, a[i].second.second) = a[i].second.second;
	}
	for (int j = 0; j < n; j++) {
		if (f[j] == 0x3f3f3f3f) {
			break;
		}
		f[j] = 0x3f3f3f3f;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}