#include <bits/stdc++.h>
using namespace std;
long long f[50] = {0, 1};
int n;
int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	cout << f[n] << ".00" << endl;
	return 0;
}
