#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int a[3];
int main() {
	scanf("%d%d%d", &a[0], &a[1], &a[2]);
	sort(a, a + 3);
	int g = __gcd(a[0], a[2]);
	printf("%d/%d\n", a[0] / g, a[2] / g);
	return 0;
}
