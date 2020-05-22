#include <bits/stdc++.h>
using namespace std;
int n, a[100020], x, z;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		a[x]++;
	}
	for (int i = 0; i < 100001; i++) {
		z = max(z, a[i - 1] + a[i] + a[i + 1]);
	}
	printf("%d\n", z);
	return 0;
}