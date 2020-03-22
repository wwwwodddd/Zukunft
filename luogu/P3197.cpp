#include <bits/stdc++.h>
using namespace std;
long long n, m, p = 100003;
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
	cin >> m >> n;
	long long a = pw(m, n, p);
	long long b = pw(m - 1, n - 1, p) * m % p;
	cout << (a + p - b) % p << endl;
}