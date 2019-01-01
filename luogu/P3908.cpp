#include <bits/stdc++.h>
using namespace std;
long long n, z;
int main() {
	cin >> n;
	for (long long i = n / 4 * 4; i <= n; i++) {
		z ^= i;
	}
	cout << z << endl;
}