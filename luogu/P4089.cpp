#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[100020];
int v[100020]; // -1 cycle, > 0 no cycle
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (v[i]) {
			continue;
		}
		int u = i;
		while (v[u] == 0) {
			v[u] = i;
			u = a[u];
		}
		if (v[u] == i) {
			while (v[u] != -1) {
				v[u] = -1;
				u = a[u];
				z++;
			}
		}
	}
	printf("%d\n", z);
	return 0;
}