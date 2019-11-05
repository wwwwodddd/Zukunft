#include <bits/stdc++.h>
using namespace std;
long long n = 17526000000000;
long long cnt;
long long T(long long n) {
	return n * (n + 1) / 2;
}
bool F(long long n) {
	long long t = sqrt(2 * n);
	return t * (t + 1) / 2 == n;
}
int main() {
//	cin >> n;
	for (long long i = 0; T(i) <= n; i++) {
		for (long long j = 0; T(i) + T(j) <= n; j++) {
			if (F(n - T(i) - T(j))) {
				cnt++;
			}
		}
		cerr << i << ' ' << clock() << endl;
	}
	cout << cnt << endl;
	return 0;
}