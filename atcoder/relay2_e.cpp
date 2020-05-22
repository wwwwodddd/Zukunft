#include <bits/stdc++.h>
using namespace std;
int n, p;
long long s, a[100020], x, y;
int main() {
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &x, &y);
		a[i] = x * (100 - p) + y * p;
		s += y * p;
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--) {
		s -= a[i];
		if (s <= 0) {
			printf("%d\n", n - i);
			break;
		}
	}
	return 0;
}