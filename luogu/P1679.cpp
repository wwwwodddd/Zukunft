#include <bits/stdc++.h>
using namespace std;
int m, f[100001];
int main() {
	cin >> m;
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 1; i * i * i * i <= m; i++) {
		for (int j = i * i * i * i; j <= m; j++) {
			f[j] = min(f[j], f[j - i * i * i * i] + 1);
		}
	}
	cout << f[m] << endl;
	return 0;
}