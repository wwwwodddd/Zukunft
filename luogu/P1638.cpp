#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000020];
int c[10020], cnt;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ansl = 0, ansr = n;
	int l = 0, r = 0;
	while (true) {
		if (cnt < m) {
			if (r == n) {
				break;
			} else {
				if (c[a[r++]]++ == 0) {
					cnt++;
				}
			}
		} else {
			if (--c[a[l++]] == 0) {
				cnt--;
			}
		}
		if (cnt == m) {
			if (ansr - ansl > r - l) {
				ansr = r;
				ansl = l;
			}
		}
	}
	printf("%d %d\n", ansl + 1, ansr);
	return 0;
}