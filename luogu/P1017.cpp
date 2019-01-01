#include <bits/stdc++.h>
using namespace std;
int n, b;
void print(int n) {
	if (n == 0) {
		return;
	}
	int r = n % b;
	if (r < 0) {
		r += b;
	}
	print((n - r) / (-b));
	if (r < 10) {
		printf("%c", r + '0');
	} else {
		printf("%c", r - 10 + 'A');
	}
}
int main() {
	scanf("%d%d", &n, &b);
	b = -b;
	if (n == 0) {
		printf("0=0(base-%d)\n", b);
	} else {
		printf("%d=", n);
		print(n);
		printf("(base-%d)\n", b);
	}
	return 0;
}