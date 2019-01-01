#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
int b[100020];
int c[100020];
map<int, int> f;
int F(int x) {
	if (f[x] == 0 || f[x] == x) {
		return x;
	}
	return f[x] = F(f[x]);
}
void U(int x, int y) {
	x = F(x);
	y = F(y);
	f[x] = y;
}
bool ok() {
	for (int i = 0; i < n; i++) {
		if (c[i] == 1) {
			U(a[i], b[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == 0) {
			if (F(a[i]) == F(b[i])) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> n;
		f.clear();
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		if (ok()) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}