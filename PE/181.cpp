#include <bits/stdc++.h>
using namespace std;
long long f[100][100];
int main() {
	int n = 60;
	int m = 40;
	f[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = (i == 0); j <= m; j++) {
			for (int k = 0; k + i <= n; k++) {
				for (int l = 0; l + j <= m; l++) {
					f[k + i][l + j] += f[k][l];
				}
			}
		}
	}
	printf("%lld\n", f[n][m]);
	return 0;
}
