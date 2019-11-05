#include <bits/stdc++.h>
using namespace std;
int P(int x) {
	x--;
	int t = 1;
	while (true) {
		if (x <= t) {
			return x + 1;
		}
		if ((x & t) == 0) {
			x -= t;
		}
		t <<= 1;
		if (x <= t) {
			return x + 1;
		}
		x -= t;
		t <<= 1;
	}
}
int F(int x) {
	int b = 0;
	while (2 << b <= x) {
		b++;
	}
	x ^= 1 << b;
	b = (b + 1) / 2;
	for (int i = 0; i < 30; i += 2) {
		if (x >> i & 1) {
			x ^= 1 << i;
		}
	}
	return ((1 << (2 * b)) + 2) / 3 + x;
}
void print(int x) {
	if (x == 0) {
		return;
	}
	print(x / 2);
	printf("%d", x % 2);
}
int main() {
	int s = 0;
	int d = 1;
//	for (int i = 1; i < 1 << 30; i <<= 1) {
//		printf("%d %d\n", i, P(i));
//	}
//	return 0;
	for (int i = d; i <= 10000; i += d) {
		assert(P(i) == F(i));
		s += P(i);
//		s += P(i);
//		printf("%d %d %d\n", i, P(i), F(i));
//		print(i);
//		printf(" ");
//		print(P(i));
//		printf("\n");
	}
	printf("%d\n", s);
	return 0;
}