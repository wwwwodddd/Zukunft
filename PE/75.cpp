#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int c[2000020];
int s[2000020];
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int main() {
	int n = 1500000;
	for (int i = 1; i * i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) > 1) {
				continue;
			}
			if (i % 2 == 1 && j % 2 == 1) {
				continue;
			}
			int sum = 2 * i * i + 2 * i * j;
			if (sum <= n) {
				c[2 * i * i + 2 * i * j] += 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			s[j] += c[i];
		}
		if (s[i] == 1) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
