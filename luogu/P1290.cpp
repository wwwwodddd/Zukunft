#include <bits/stdc++.h>
using namespace std;
int t, n, m;
bool F(int n, int m) {
	if (m == 0) {
		return false;
	}
	if (n / m == 1) {
		return !F(m, n % m);
	}
	return true;
}
int main() {
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> n >> m;
		if (n < m) {
			swap(n, m);
		}
		if (F(n, m)) {
			cout << "Stan wins" << endl;
		} else {
			cout << "Ollie wins" << endl;
		}
	}
}