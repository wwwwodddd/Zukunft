#include <bits/stdc++.h>
using namespace std;
int n, x;
long long sx, sn, zx, zn;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		sx += x;
		sn += x;
		if (sx < 1) {
			zx += 1 - sx;
			sx = 1;
		}
		if (sn > -1) {
			zn += sn + 1;
			sn = -1;
		}
		swap(sx, sn);
		swap(zx, zn);
	}
	printf("%lld\n", min(zx, zn));
	return 0;
}