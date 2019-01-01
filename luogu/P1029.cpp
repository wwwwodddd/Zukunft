#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int main() {
	cin >> n >> m;
	if (m % n > 0) {
		cout << 0 << endl;
		return 0;
	}
	m /= n;
	for (int i = 2; i * i <= m; i++) {
		if (m % i == 0) {
			z++;
			while (m % i == 0) {
				m /= i;
			}
		}
	}
	if (m > 1) {
		z++;
	}
	cout << (1 << z) << endl;
	return 0;
}