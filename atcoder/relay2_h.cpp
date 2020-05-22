#include <bits/stdc++.h>
using namespace std;
int p[7] = {2, 3, 5, 7, 11, 13, 17};
int q[7] = {9, 6, 4, 3, 3, 3, 3};
int r[7];
int n, z, pc = 7;
int a[320];
int b[320];
int w[320];
void dfs(int x) {
	if (x == pc) {
		memset(w, 0, sizeof w);
		for (int i = 0; i < n; i++) {
			bool flag = false;
			int u = a[i];
			int v = b[i];
			for (int j = 0; j < pc; j++) {
				for (int k = 0; k < r[j]; k++) {
					if (u % p[j] == 0) {
						u /= p[j];
					} else {
						break;
					}
				}
				if (u % p[j] == 0) {
					flag = true;
					break;
				}
			}
			if (flag) {
				continue;
			}
			w[u] += v;
		}
		int t = w[1];
		for (int i = 2; i <= 300; i++) {
			if (w[i] > 0) {
				t += w[i];
			}
		}
		z = max(z, t);
	} else {
		for (r[x] = 0; r[x] < q[x]; r[x]++) {
			dfs(x + 1);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	dfs(0);
	printf("%d\n", z);
	return 0;
}