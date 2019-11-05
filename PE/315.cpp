#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[] = {119, 36, 93, 109, 46, 107, 123, 39, 127, 111, 0};
int v[20000020];
int calc(int x, int y) {
	int u = a[x] ^ a[y];
	return __builtin_popcount(u);
}
int burgerking(int x, int y) {
	int a[20], c = 0;
	int b[20], d = 0;
	if (x == 0) {
		a[c++] = 0;
	}
	while (x > 0) {
		a[c++] = x % 10;
		x /= 10;
	}
	if (y == 0) {
		b[d++] = 0;
	}
	while (y > 0) {
		b[d++] = y % 10;
		y /= 10;
	}
	while (c < 20) {
		a[c++] = 10;
	}
	while (d < 20) {
		b[d++] = 10;
	}
	int res = 0;
	for (int i = 0; i < 20; i++) {
		res += calc(a[i], b[i]);
	}
	return res;

}
long long ans1 = 0;
long long ans2 = 0;
int last = -1;
int fuck(int x) {
	if (x < 10) {
		return x;
	}
	return x % 10 + fuck(x / 10);
}
void work(int x) {
	last = -1;
	while (true) {
		ans1 += 2 * burgerking(x, -1);
		ans2 += burgerking(last, x);
		last = x;
		if (x < 10) {
			break;
		}
		x = fuck(x);
	}
	ans2 += burgerking(last, -1);
}
int main() {
	int n = 20000000;
	for (int i = 2; i <= n; i++) {
		if (v[i] == 1) {
			continue;
		}
		for (int j = 2 * i; j <= n; j += i) {
			v[j] = 1;
		}
	}
	for (int i = n / 2; i <= n; i++) {
		if (v[i] == 0) {
//			printf("%d\n", i);
			work(i);
		}
	}
	printf("%lld %lld %lld\n", ans1, ans2, ans1 - ans2);
	return 0;
}