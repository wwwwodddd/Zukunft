#include <bits/stdc++.h>
using namespace std;
int n, k, a[100020];
long long s;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		a[i] = a[i + 1] - a[i];
	}
	sort(a, a + n - 1);
	for (int i = 0; i < k; i++) {
		s += a[i];
	}
	printf("%lld\n", s);
	return 0;
}