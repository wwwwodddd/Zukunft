#include <bits/stdc++.h>
using namespace std;
int f[10000020];
int v[10000020];
int n = 10000000;
long long m = 1e18, z;
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
	f[2] = 1;
	for (int i = 3; i <= n; i++) {
		if (v[i] == v[i / v[i]]) {
			f[i] = f[i / v[i]] * v[i];
		} else {
			f[i] = f[i / v[i]] * (v[i] - 1);
		}
		if (m >= (long long)i * f[i] / 2) {
			m -= (long long)i * f[i] / 2;
			z += f[i];
		} else {
			z += m / i * 2;
			m -= m / i * i;
			if (m > 0) {
				z++;
			}
			break;
		}
	}
	z++;
	cout << z << endl;
	return 0;
}

// answer is 1398582231101