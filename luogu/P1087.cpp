#include <bits/stdc++.h>
using namespace std;
int n;
char s[9999];
char gao(int l, int r) {
	if (l + 1 == r) {
		if (s[l] == '0') {
			printf("B");
			return 'B';
		} else {
			printf("I");
			return 'I';
		}
	}
	char L = gao(l, (l + r) / 2);
	char R = gao((l + r) / 2, r);
	if (L == 'B' && R == 'B') {
		printf("B");
		return 'B';
	} else if (L == 'I' && R == 'I') {
		printf("I");
		return 'I';
	} else {
		printf("F");
		return 'F';
	}
}
int main() {
	scanf("%d%s", &n, s);
	gao(0, 1 << n);
}