#include <bits/stdc++.h>
using namespace std;
int n, f[1020];
int main() {
	f[1] = 1;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) {
			f[i] += f[j];
		}
		f[i]++;
	}
	cout << f[n] << endl;
	return 0;
}
