#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int c = (a[0] >= a[n - 1]);
		for (int i = 1; i < n; i++) {
			c += (a[i] >= a[i - 1]);
		}
		printf("%s\n", c >= n - 1 ? "YES" : "NO");
	}
	return 0;
}