#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n, m, a, b;
	cin >> n >> m;
	if (n > m) {
		swap(n, m);
	}
	a = n * (n + 1) * m * (m + 1) / 4;
	b = n * (n + 1) * (3 * m - n + 1) / 6;
	cout << b << ' ' << a - b << endl;
	return 0;
}
