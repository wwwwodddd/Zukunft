#include <bits/stdc++.h>
using namespace std;
int n, z;
int main() {
	cin >> n;
	if (n < 0) {
		cout << '-';
		n = -n;
	}
	while (n > 0) {
		z = 10 * z + n % 10;
		n /= 10;
	}
	cout << z << endl;
	return 0;
}
