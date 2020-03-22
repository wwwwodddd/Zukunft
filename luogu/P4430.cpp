#include <bits/stdc++.h>
using namespace std;
int n, p = 9999991;
long long ans = 1;
int main() {
	cin >> n;
	for (int i = 0; i < n - 2; i++) {
		ans = ans * n % p;
	}
	for (int i = 1; i <= n - 1; i++) {
		ans = ans * i % p;
	}
	cout << ans << endl;
}