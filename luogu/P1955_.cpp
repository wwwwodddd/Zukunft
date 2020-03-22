#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
int b[100020];
int c[100020];
int l[200020], lc;
int f[200020];
int F(int x) {
	if (f[x] == x) {
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
		lc = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			l[lc++] = a[i];
			l[lc++] = b[i];
		}
		sort(l, l + lc);
		lc = unique(l, l + lc) - l;
		for (int i = 0; i < n; i++) {
			a[i] = lower_bound(l, l + lc, a[i]) - l;
			b[i] = lower_bound(l, l + lc, b[i]) - l;
		}
		for (int i = 0; i < lc; i++) {
			f[i] = i;
		}
		if (ok()) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}