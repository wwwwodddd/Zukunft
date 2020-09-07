#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000020];
int c[10020], cnt;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0, j = 0; j < n; j++) {
		scanf("%d", &a[j]);
	}
	int ansi = 0, ansj = n;
	for (int i = 0, j = 0; i < n;) {
		while (j < n && cnt < m) {
			cnt += !c[a[j++]]++;
		}
		if (cnt == m) {
			if (ansj - ansi > j - i) {
				ansj = j;
				ansi = i;
			}
		}
		cnt -= !--c[a[i++]];
	}
	printf("%d %d\n", ansi + 1, ansj);
	return 0;
}