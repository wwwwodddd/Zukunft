#include <bits/stdc++.h>
using namespace std;
int n, m, k, x;
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
	cin >> n >> m >> k >> x;
	cout << (x + m * pw(10, k, n)) % n << endl;
}