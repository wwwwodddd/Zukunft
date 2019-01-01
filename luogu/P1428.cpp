#include <bits/stdc++.h>
using namespace std;
int n, a[1020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int z = 0;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				z++;
			}
		}
		printf("%d%c", z, i == n - 1 ? '\n' : ' ');
	}
	return 0;
}
