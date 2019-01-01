#include <bits/stdc++.h>
using namespace std;
int n, z, h[100020];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
		z += max(h[i] - h[i - 1], 0);
	}
	printf("%d\n", z);
	return 0;
}