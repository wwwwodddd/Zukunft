#include <bits/stdc++.h>
using namespace std;
long long C(int n, int m) {
	long long z = 1;
	for (int i = 0; i < m; i++) {
		z = z * (n - i) / (i + 1);
	}
	return z;
}
int main() {
	int n;
	cin >> n;
	cout << C(2 * n, n) - C(2 * n, n - 1) << endl;
	return 0;
}