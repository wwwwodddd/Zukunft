#include <bits/stdc++.h>
using namespace std;
long long n, s, m;
long long f[1020];
int main() {
	cin >> n >> s >> m;
	f[1] = s;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] * s % m;
		f[i] = (f[i] - f[(i + 1) / 2] + m) % m;
	}
	cout << f[n] << endl;
	return 0;
}
