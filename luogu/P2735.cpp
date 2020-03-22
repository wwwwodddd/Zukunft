#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int main() {
	cin >> n >> m >> p;
	cout << (m * p + 2 - p - gcd(n, m) - gcd(abs(n - p), m)) / 2 << endl;
	return 0;
}