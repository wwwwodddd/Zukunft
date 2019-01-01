#include <bits/stdc++.h>
using namespace std;
int f[220][220]; // i的金钱, j的时间  i的金钱，j个任务，最小的时间
int n, m, t, x, y;
int main() {
	cin >> n >> m >> t;
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i <= m; i++) {
		f[i][0] = 0;
	}
	for (int k = 0; k < n; k++) {
		cin >> x >> y;
		for (int i = m; i >= x; i--) {
			for (int j = n; j >= 1; j--) {
				f[i][j] = min(f[i][j], f[i - x][j - 1] + y);
			}
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		if (f[m][i] > t) {
			printf("%d\n", i - 1);
			break;
		}
	}
}