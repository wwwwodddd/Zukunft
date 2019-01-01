#include <bits/stdc++.h>
using namespace std;
long long f[100020], z;
int n, m;
int main() {
	cin >> n >> m;
	if (n > m) {
		swap(n, m);
	}
	for (int i = n; i > 0; i--) {
		f[i] = (long long)(n / i) * (m / i);
		for (int j = i + i; j <= n; j += i) {
			f[i] -= f[j];
		}
		z += f[i] * (2 * i - 1);
	}
	cout << z << endl;
}