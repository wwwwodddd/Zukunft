#include <bits/stdc++.h>
using namespace std;
int f[5000000], m;
int main() {
	f[0] = 0;
	f[1] = 1;
	cin >> m;
	for (int i = 1;; i++) {
		f[i + 1] = (f[i] + f[i - 1]) % m;
		if (f[i] == 0 && f[i + 1] == 1) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}