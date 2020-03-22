#include <bits/stdc++.h>
using namespace std;
int n, ans;
int x[120], y[120];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	x[n] = x[0];
	y[n] = y[0];
	for (int i = 0; i < n; i++) {
		ans += x[i] * y[i + 1] - x[i + 1] * y[i];
	}
	cout << ans / 2 << endl;
	return 0;
}