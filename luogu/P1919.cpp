#include <bits/stdc++.h>
using namespace std;
char s[60020];
long long a[14020];
long long b[14020];
long long c[14020];
int T = 9, B = 1;
int main() {
	scanf("%*d");
	for (int i = 0; i < T; i++) {
		B = B * 10;
	}
	scanf("%s", s);
	int la = strlen(s);
	reverse(s, s + la);
	for (int i = 0; i < la; i++) {
		s[i] -= '0';
	}
	for (int i = 0; i * T < la; i++) {
		for (int j = T - 1; j >= 0; j--) {
			a[i] = a[i] * 10 + s[i * T + j];
		}
	}
	la = (la + T - 1) / T;

	scanf("%s", s);
	int lb = strlen(s);
	reverse(s, s + lb);
	for (int i = 0; i < lb; i++) {
		s[i] -= '0';
	}
	for (int i = 0; i * T < lb; i++) {
		for (int j = T - 1; j >= 0; j--) {
			b[i] = b[i] * 10 + s[i * T + j];
		}
	}
	lb = (lb + T - 1) / T;
	int lc = la + lb;
	for (int i = 0; i < la; i++) {
		for (int j = 0; j < lb; j++) {
			c[i + j] += a[i] * b[j];
			c[i + j + 1] += c[i + j] / B;
			c[i + j] %= B;
		}
	}

	while (lc > 1 && c[lc - 1] == 0) {
		lc--;
	}

	printf("%d", (int)c[lc - 1]);
	for (int i = lc - 2; i >= 0; i--) {
		printf("%09d", (int)c[i]);
	}

	printf("\n");
	return 0;
}