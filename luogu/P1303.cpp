#include <bits/stdc++.h>
using namespace std;
char s[4020];
int a[4020];
int b[4020];
int c[4020];
int main() {
	scanf("%s", s);
	int la = strlen(s);
	for (int i = 0; i < la; i++) {
		a[i] = s[i] - '0';
	}
	reverse(a, a + la);

	scanf("%s", s);
	int lb = strlen(s);
	for (int i = 0; i < lb; i++) {
		b[i] = s[i] - '0';
	}
	reverse(b, b + lb);

	int lc = la + lb;
	for (int i = 0; i < la; i++) {
		for (int j = 0; j < lb; j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	for (int i = 0; i < lc; i++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	while (lc > 1 && c[lc - 1] == 0) {
		lc--;
	}
	for (int i = lc - 1; i >= 0; i--) {
		printf("%d", c[i]);
	}
	printf("\n");
	return 0;
}