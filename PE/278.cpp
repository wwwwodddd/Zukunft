#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int f[N + 10000];
int cao(int x, int y, int z) {
	int a = x * y;
	int b = y * z;
	int c = z * x;
	memset(f, 0, sizeof f);
	f[0] = 1;
	for (int i = 0; i < N; i++) {
		if (f[i]) {
			f[i + a] = 1;
			f[i + b] = 1;
			f[i + c] = 1;
		}
	}
	for (int i = N; i >= 0; i--) {
		if (!f[i]) {
			return i;
		}
	}
	return -1;
}
bool P(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
long long F(long long a, long long b, long long c) {
	return 2 * a * b * c - a * b - b * c - c * a;
}
int p[5000], pp;
int main() {
	for (int i = 1; i <= 5000; i++) {
		if (P(i)) {
			p[pp++] = i;
		}
	}
	cerr << pp << endl;
	long long s = 0;
	for (int i = 0; i < pp; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				s += F(p[i], p[j], p[k]);
			}
		}
	}
	cerr << s << endl;
}
