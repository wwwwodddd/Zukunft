#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[100020];
long long z;
int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int d = max(a[i] + a[i - 1] - x, 0);
		a[i] -= d;
		z += d;
	}
	cout << z << endl;
	return 0;
}