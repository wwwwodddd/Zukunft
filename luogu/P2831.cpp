#include <bits/stdc++.h>
using namespace std;
int t, n, f[262147];
double x[20], y[20];
void upd(int x) {
	for (int i = 0; i < 1 << n; i++) {
		f[i | x] = min(f[i | x], f[i] + 1);
	}
}
bool in(int i, int j, int k) {
	double s = 0;
	s += x[i] * x[i] * x[j] * y[k];
	s += x[j] * x[j] * x[k] * y[i];
	s += x[k] * x[k] * x[i] * y[j];
	s -= x[i] * x[i] * x[k] * y[j];
	s -= x[j] * x[j] * x[i] * y[k];
	s -= x[k] * x[k] * x[j] * y[i];
	return s == 0;
}
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		memset(f, 0x3f, sizeof f);
		f[0] = 0;
		scanf("%d%*d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &x[i], &y[i]);
			x[i] = (int)(100 * x[i] + 0.5);
			y[i] = (int)(100 * y[i] + 0.5);
		}
		for (int i = 0; i < n; i++) {
			upd(1 << i);
			for (int j = 0; j < n; j++) {
				if (x[j] > x[i] && y[i] * (x[j] - x[i]) > (y[j] - y[i]) * x[i]) {
					int b = (1 << i) | (1 << j);
					for (int k = 0; k < n; k++) {
						if (in(i, j, k)) {
							b |= 1 << k;
						}
					}
					upd(b);
				}
			}
		}
		printf("%d\n", f[(1 << n) - 1]);
	}
}