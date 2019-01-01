#include <bits/stdc++.h>
using namespace std;
int a[3000];
int n, m, s, z = 1e9;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m - 1; i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	for (int i = m - 1; i < n; i++) {
		scanf("%d", &a[i]);
		s += a[i];
		z = min(z, s);
		s -= a[i - m + 1];
	}
	printf("%d\n", z);
	return 0;
}