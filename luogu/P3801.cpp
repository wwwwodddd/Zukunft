#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int ax[100020];
int ay[100020];
int cx[100020];
int cy[100020];
void change(int c[], int x, int y) {
	for (int i = x; i <= n; i += i & -i) {
		c[i] += y;
	}
}
int query(int c[], int x) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re += c[i];
	}
	return re;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	n = max(n, m);
	for (int i = 0; i < q; i++) {
		int o;
		scanf("%d", &o);
		if (o == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (ax[x]) {
				change(cx, x, -1);
			} else {
				change(cx, x, 1);
			}
			ax[x] ^= 1;
			if (ay[y]) {
				change(cy, y, -1);
			} else {
				change(cy, y, 1);
			}
			ay[y] ^= 1;
		} else {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			long long lx = x2 - x1 + 1, ly = y2 - y1 + 1;
			int sx = query(cx, x2) - query(cx, x1 - 1);
			int sy = query(cy, y2) - query(cy, y1 - 1);
			printf("%lld\n", (lx - sx) * sy + (ly - sy) * sx);
		}
	}
	return 0;
}