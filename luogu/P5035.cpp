#include <bits/stdc++.h>
using namespace std;
long long n, p = 123456789;
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
	cin >> n;
	cout << pw(2, n-1, p) << endl;
	return 0;
}