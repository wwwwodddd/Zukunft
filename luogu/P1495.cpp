#include <bits/stdc++.h>
using namespace std;
int n, a[10], b[10];
long long m = 1, z;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		m *= a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++) {
			if (m / a[i] * j % a[i] == 1) {
				z += m / a[i] * j * b[i];
			}
		}
	}
	cout << z % m << endl;
}