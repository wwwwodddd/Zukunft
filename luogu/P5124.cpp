#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10020];
int f[10020];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int mx = a[i];
		for (int j = 1; j <= m && j <= i; j++) {
			f[i] = max(f[i], f[i - j] + mx * j);
			mx = max(mx, a[i - j]);
		}
	}
	cout << f[n] << endl;
	return 0;
}