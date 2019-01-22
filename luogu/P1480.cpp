#include <bits/stdc++.h>
using namespace std;
char s[5020];
int a[5020];
int b;
int main() {
	scanf("%s%d", s, &b);
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		a[i] = s[n - i - 1] - '0';
	}
	int u = 0;
	for (int i = n - 1; i >= 0; i--) {
		u = u * 10 + a[i];
		a[i] = u / b;
		u %= b;
	}
	while (n > 1 && a[n - 1] == 0) {
		n--;
	}
	for (int i = n - 1; i >= 0; i--) {
		printf("%d", a[i]);
	}
	printf("\n");
}