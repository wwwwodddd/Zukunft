#include <bits/stdc++.h>
using namespace std;
int n, m, l;
char s[100];
long long z;
void print(long long z) {
	if (z == 0) {
		return;
	}
	print(z / m);
	printf("%X", z % m);
}
int main() {
	scanf("%d%s%d", &n, s, &m);
	l = strlen(s);
	for (int i = 0; i < l; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			z = z * n + s[i] - '0';
		} else {
			z = z * n + s[i] - 'A' + 10;
		}
	}
	if (z == 0) {
		printf("0\n");
	} else {
		print(z);
		printf("\n");
	}
	return 0;
}