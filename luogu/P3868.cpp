#include <bits/stdc++.h>
using namespace std;
int n, a[10], b[10];
long long m = 1, z;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		a[i] = (a[i] % b[i] + b[i]) % b[i];
		m *= b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < b[i]; j++) {
			if (m / b[i] * j % b[i] == a[i]) {
				z = (z + m / b[i] * j) % m;
			}
		}
	}
	cout << z << endl;
	return 0;
}