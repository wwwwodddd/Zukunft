#include <bits/stdc++.h>
using namespace std;
char a[2020];
char b[2020];
char c[2020];
int base;
int main() {
	scanf("%d%s%s", &base, a, b);
	int la = strlen(a);
	int lb = strlen(b);
	reverse(a, a + la);
	reverse(b, b + lb);
	for (int i = 0; i < la; i++) {
		if (isdigit(a[i])) {
			a[i] -= '0';
		} else {
			a[i] = a[i] - 'A' + 10;
		}
	}
	for (int i = 0; i < lb; i++) {
		if (isdigit(b[i])) {
			b[i] -= '0';
		} else {
			b[i] = b[i] - 'A' + 10;
		}
	}
	int lc = max(la, lb);
	for (int i = 0; i < lc; i++) {
		c[i] = a[i] + b[i];
	}
	for (int i = 0; i < lc; i++) {
		c[i + 1] += c[i] / base;
		c[i] %= base;
	}
	if (c[lc] > 0) {
		lc++;
	}
	for (int i = lc - 1; i >= 0; i--) {
		if (c[i] < 10) {
			printf("%d", c[i]);
		} else {
			printf("%c", c[i] - 10 + 'A');
		}
	}
	printf("\n");
	return 0;
}