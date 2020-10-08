#include <bits/stdc++.h>
using namespace std;
int n;
long long f[1020];
bool Prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	cin >> n;
	f[0] = 1;
	for (int i = 2; i <= n; i++) {
		if (Prime(i)) {
			for (int j = i; j <= n; j++) {
				f[j] += f[j - i];
			}
		}
	}
	cout << f[n] << endl;
	return 0;
}