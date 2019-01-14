#include <bits/stdc++.h>
using namespace std;
int F(int x) {
	int b = 1;
	while (x % 2 == 0) {
		x /= 2;
		b *= 2;
	}
	return b;
}
int main() {
    int n;
	scanf("%d", &n);
	for (int cnt = 0; cnt < 500; cnt++) {
		int x = F(n);
		printf("%d\n", x);
		n -= x;
		fflush(stdout);
		scanf("%d", &x);
		n -= x;
		if (n == 0) {
			break;
		}
	}
}