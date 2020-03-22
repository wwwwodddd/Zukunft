#include <bits/stdc++.h>
using namespace std;
bool f[5000001];
int n, b, c;
int main() {
	cin >> n >> b >> c;
	f[0] = true;
	for (int i = 0; i < n; i++) {
		if (i + b <= n) {
			f[i + b] |= f[i];
		}
		if (i + c <= n) {
			f[i + c] |= f[i];
		}
	}
	for (int i = 0; i <= n; i++) {
		f[i / 2] |= f[i];
	}
	for (int i = 0; i < n; i++) {
		if (i + b <= n) {
			f[i + b] |= f[i];
		}
		if (i + c <= n) {
			f[i + c] |= f[i];
		}
	}
	for (int i = n; i >= 0; i--) {
		if (f[i]) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}