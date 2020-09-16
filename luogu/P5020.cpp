#include <bits/stdc++.h>
using namespace std;
int f[25020];
int a[120];
int t, n;
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		memset(f, 0, sizeof f);
		f[0] = 1;
		int z = 0;
		for (int i = 0; i < n; i++) {
			if (f[a[i]] == 0) {
				z++;
				for (int j = a[i]; j <= a[n - 1]; j++) {
					f[j] |= f[j - a[i]];
				}
			}
		}
		printf("%d\n", z);
	}
	return 0;
}