#include <bits/stdc++.h>
using namespace std;
int n, x, z, f[30];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		int t = 0;
		for (int j = 0; j < 30; j++) {
			if (x >> j & 1) {
				t = max(t, f[j]);
			}
		}
		t++;
		z = max(z, t);
		for (int j = 0; j < 30; j++) {
			if (x >> j & 1) {
				f[j] = max(f[j], t);
			}
		}
	}
	cout << z << endl;
	return 0;
}