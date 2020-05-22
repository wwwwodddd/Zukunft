#include <bits/stdc++.h>
using namespace std;
int n, p = 1000000007;
string s;
long long f[5020][5020];
int main() {
	f[0][0] = 1;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j] = (f[i - 1][max(j - 1, 0)] + f[i - 1][j + 1] * 2) % p;
		}
	}
	cout << f[n][s.size()] << endl;
	return 0;
}