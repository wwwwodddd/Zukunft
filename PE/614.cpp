#include <bits/stdc++.h>
using namespace std;
int f[10000020];
int p = 1000000007;
int main() {
	f[0] = 1;
	int n = 10000000;
	for (int i = 1; i <= n; i++) {
		if (i % 1000 == 0) {
			cerr << i << endl;
		}
		if (i % 4 == 2) {
			continue;
		}
		for (int j = n; j >= i; j--) {
			f[j] += f[j - i];
			if (f[j] >= p) {
				f[j] -= p;
			}
		}
	}
	cerr << f[n] << endl;
	int s = 0;
	for (int i = 1; i <= n; i++) {
		s += f[i];
		if (s >= p) {
			s -= p;
		}
	}
	cerr << s << endl;
	return 0;
}
