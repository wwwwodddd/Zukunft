#include <bits/stdc++.h>
using namespace std;
int b;
char s[1020];
int main() {
	scanf("%d%s", &b, s);
	int l = strlen(s);
	for (int i = 0; i < l; i++) {
		if (s[i] != '0') {
			if (i > 0) {
				printf("+");
			}
			printf("%d*%d^%d", s[i] - '0', b, l - i - 1);
		}
	}
	printf("\n");
	return 0;
}