#include <bits/stdc++.h>
using namespace std;
int cases, s, a;
int t[6300020][2], tt;
int n, m, x;
void insert(int x) {
	int p = 0;
	for (int i = 30; i >= 0; i--) {
		if (t[p][x >> i & 1] == 0) {
			t[p][x >> i & 1] = ++tt;
		}
		p = t[p][x >> i & 1];
	}
}
int query(int x) {
	int p = 0, re = 0;
	for (int i = 30; i >= 0; i--) {
		if (t[p][~x >> i & 1] > 0) {
			p = t[p][~x >> i & 1];
			re += 1 << i;
		} else {
			p = t[p][x >> i & 1];
		}
	}
	return re;
}
int main() {
	for (scanf("%d", &cases); cases--;) {
		tt = 0;
		memset(t, 0, sizeof t);
		scanf("%d%d", &n, &x);
		int z = 0;
		for (int i = 1; i <= n; i++) {
			insert(s);
			scanf("%d", &a);
			s ^= a;
			z = max(z, query(s ^ x));
		}
		printf("%d\n", z ^ x);
	}
	return 0;
}