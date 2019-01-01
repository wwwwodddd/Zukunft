#include <bits/stdc++.h>
using namespace std;
int n, m, z, p = 1000000007;
int f[2020];
int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		f[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = m; j > 0; j--) {
			for (int k = j + j; k <= m; k += j) {
				f[k] = (f[k] + f[j]) % p;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		z = (z + f[i]) % p;
	}
	cout << z << endl;
	return 0;
}