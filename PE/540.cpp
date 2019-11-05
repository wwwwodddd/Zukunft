#include <bits/stdc++.h>
using namespace std;
int n = 100000000;
int v[100000020];
int f[100000020];
long long w[100000020];
int pw(int x, int y, int p) {
	int re = 1;
	for (; y; y >>= 1) {
		if (y & 1) {
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}

int main() {
	for (int i = 2; i <= n; i++) {
		if (v[i] > 0) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (v[i] == v[i / v[i]]) {
			f[i] = f[i / v[i]] * v[i];
		} else {
			f[i] = f[i / v[i]] * (v[i] - 1);
		}
	}
	long long gg = -1;
	long long L = 3141592653589793;
	for (long long g = 1; g * g <= L; g += 2) {
		long long nn = L / (g * g);
		for (long long x = 2; x * x <= nn; x++) {
			long long up = sqrt(nn - x * x);
			if (x % 2 == 0) {
				up++;
			}
			w[g] += min(x / 2, up / 2);
		}
		gg = g;
	}
//	for (int i = 1; i <= gg; i++) {
//		printf("%d %lld\n", i, w[i]);
//	}
	for (int g = gg; g >= 1; g--) {
		for (int i = g + g; i <= gg; i += g) {
			w[g] -= w[i];
		}
	}
	cout << w[1] << endl;
	return 0;
}