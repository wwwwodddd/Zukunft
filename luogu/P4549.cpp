#include <bits/stdc++.h>
using namespace std;
int n, x, z;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		z = __gcd(z, abs(x));
	}
	cout << z << endl;
}