#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int f[150020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y) {
	x = F(x);
	y = F(y);
	f[x] = y;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= 3 * n; i++) {
		f[i] = i;
	}
	for (int i = 0; i < k; i++) {
		int o, x, y;
		cin >> o >> x >> y;
		if (x > n || y > n) {
			ans++;
		} else {
			if (o == 1) {
				if (F(x) == F(y + n) || F(x) == F(y + 2 * n)) {
					ans++;
				} else {
					U(x, y);
					U(x + n, y + n);
					U(x + 2 * n, y + 2 * n);
				}
			} else {
				if (F(x) == F(y) || F(x) == F(y + n)) {
					ans++;
				} else {
					U(x, y + 2 * n);
					U(x + n, y);
					U(x + 2 * n, y + n);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}