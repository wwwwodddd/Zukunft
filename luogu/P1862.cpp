#include <bits/stdc++.h>
using namespace std;
int n, z;
int y[10020];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y[i] >> y[i];
	}
	sort(y, y + n);
	for (int i = 0; i < n; i++) {
		z += abs(y[i] - y[n / 2]);
	}
	cout << z << endl;
	return 0;
}