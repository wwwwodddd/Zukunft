// DNF
#include <iostream>
#include <cstdio>
using namespace std;
int a, b, c;
int F(int x) {
	if (x <= b) {
		return F(a + F(a + F(a + F(a + x))));
	} else {
		return x - c;
	}
}


// F(x) = G(x) - c
int G(int x) {
	if (x <= b) {
		return G(a + G(a + G(a + G(a + x) - c) - c) - c);
	} else {
		return x;
	}
}

int p = 1000000000;


int main() {
	a = 1801088541;
	b = 558545864083284007;
	c = 35831808;
	long long ans = (b * (b + 1) / 2 - (b + 1) * c) % p;
	long long cnt = b + 1;
	cnt += a * (b / a) * (b / a - 1) / 2 + (b % a + 1) * (b / a);
	for (int i = 0; i <= b; i++) {
//		int t = i / a;
//		cnt += t;
//		ans += t * (4 * a - 3 * c);
//		if (H(i) != F(i)) {
//			printf("%d %d %d %d\n", i, G(i) - c, F(i), H(i));
//		}
	}
	ans += cnt * (4 * a - 3 * c);
	printf("%lld\n", ans);
	return 0;
}