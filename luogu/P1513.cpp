#include <bits/stdc++.h>
using namespace std;
int n;
double x[101], y[101], z;
int main() {
	cin >> n >> z;
	z = z * 2 * acos(-1.);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	x[n] = x[0];
	y[n] = y[0];
	for (int i = 0; i < n; i++) {
		z += hypot(x[i] - x[i + 1], y[i] - y[i + 1]);
	}
	cout << fixed << setprecision(2) << z << endl;
	return 0;
}