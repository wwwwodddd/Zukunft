#include <bits/stdc++.h>
using namespace std;
char a[1020];
char b[1020];
char c[1020];
int main() {
	scanf("%s%s", a, b);
	int la = strlen(a);
	int lb = strlen(b);
	reverse(a, a + la);
	reverse(b, b + lb);
	for (int i = 0; i < la; i++) {
		a[i] -= '0';
	}
	for (int i = 0; i < lb; i++) {
		b[i] -= '0';
	}
	int lc = max(la, lb);
	for (int i = 0; i < lc; i++) {
		c[i] = a[i] + b[i];
	}
	for (int i = 0; i < lc; i++) {
		while (c[i] >= 10) {
			c[i] -= 10;
			c[i + 1] += 1;
		}
	}
	if (c[lc] > 0) {
		lc++;
	}
	for (int i = lc - 1; i >= 0; i--) {
		printf("%d", c[i]);
	}
	printf("\n");
	return 0;
}