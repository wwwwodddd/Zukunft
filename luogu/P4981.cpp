#include <bits/stdc++.h>
using namespace std;
int t, n, p = 1000000009;
long long pw(long long x, long long y, long long p) {
	long long re = 1;	
	for (; y; y >>= 1) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
int main() {
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> n;
		cout << pw(n, n - 1, p) << endl;
	}
}