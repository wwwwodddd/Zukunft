#include <bits/stdc++.h>
using namespace std;
int n, z;
int x[10020];
int y[10020];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	sort(x, x + n);
	sort(y, y + n);
	for (int i = 0; i < n; i++) {
		x[i] -= i;
	}
	sort(x, x + n);
	for (int i = 0; i < n; i++) {
		z += abs(x[i] - x[n / 2]) + abs(y[i] - y[n / 2]);
	}
	cout << z << endl;
	return 0;
}