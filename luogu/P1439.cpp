#include <bits/stdc++.h>
using namespace std;
int n, x;
int p[100020];
int f[100020];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		p[x] = i;
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		x = p[x];
		*upper_bound(f, f + n, x) = x;
	}
	cout << (lower_bound(f, f + n, 0x3f3f3f3f) - f) << endl;
	return 0;
}