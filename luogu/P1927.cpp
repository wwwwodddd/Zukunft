#include <bits/stdc++.h>
using namespace std;
int n;
int x[1020];
int y[1020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	int z = 1e9;
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < n; j++) {
			t = max(t, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		}
		z = min(z, t);
	}
	printf("%.4f\n", z * 3.1415926535);
	return 0;
}