#include <bits/stdc++.h>
using namespace std;
int t;
int a[256];
int b[256];
int c[256];
bool ok(int x, int y) {
	for (int k = 0; k < 256; k++) {
		if (x * a[k] + y * b[k] != c[k]) {
			return false;
		}
	}
	return true;
}
bool work() {
	for (int x = 1; x < 100; x++) {
		for (int y = 1; y < 100; y++) {
			if (ok(x, y)) {
				printf("%d %d\n", x, y);
				return true;
			}
		}
	}
	return false;
}
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		int n, m, l;
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof a);
		memset(c, 0, sizeof a);
		scanf("%d%d%d", &n, &m, &l);
		for (int i = 0; i < n; i++) {
			char ch;
			int in;
			scanf(" %c%d", &ch, &in);
			a[ch] += in;
		}
		for (int i = 0; i < m; i++) {
			char ch;
			int in;
			scanf(" %c%d", &ch, &in);
			b[ch] += in;
		}
		for (int i = 0; i < l; i++) {
			char ch;
			int in;
			scanf(" %c%d", &ch, &in);
			c[ch] += in;
		}
		if (!work()) {
			printf("NO\n");
		}
	}
}