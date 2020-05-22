#include <bits/stdc++.h>
using namespace std;
int n;
int a[200020];
long long z;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] -= i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		z += abs(a[i] - a[n / 2]);
	}
	printf("%lld\n", z);
	return 0;
}