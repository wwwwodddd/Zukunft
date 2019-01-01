#include <bits/stdc++.h>
using namespace std;
int f[30020];
int b[30020];
int c[30020];
int F(int x) {
	if (f[x] == x) {
		return x;
	}
	int fx = F(f[x]);
	b[x] += b[f[x]];
	f[x] = fx;
	return f[x];
}
void U(int x, int y) {
	x = F(x);
	y = F(y);
	if (x != y) {
		f[x] = y;
		b[x] = c[y];
		c[y] += c[x];
	}
}
int main() {
	for (int i = 1; i <= 30000; i++) {
		f[i] = i;
		c[i] = 1;
		b[i] = 0;
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char o;
		int x, y;
		scanf(" %c%d%d", &o, &x, &y);
		if (o == 'M') {
			U(x, y);
		} else if (o == 'C') {
			if (F(x) != F(y)) {
				printf("-1\n");
			} else {
				printf("%d\n", abs(b[x] - b[y]) - 1);
			}
		}
	}
	return 0;
}