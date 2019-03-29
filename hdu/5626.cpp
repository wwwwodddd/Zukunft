#include <bits/stdc++.h>
using namespace std;
int t, n;
long long seed;
inline long long rand(long long l, long long r) {
	static long long mo=1e9+7, g=78125;
	return l+((seed*=g)%=mo)%(r-l+1);
}
int main() {
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> n >> seed;
		long long pmx = -1e18, pmn = 1e18;
		long long mmx = -1e18, mmn = 1e18;
		for (int i = 0; i < n; i++) {
			long long x = rand(-1000000000, 1000000000);
			long long y = rand(-1000000000, 1000000000);
			pmx = max(pmx, x + y);
			pmn = min(pmn, x + y);
			mmx = max(mmx, x - y);
			mmn = min(mmn, x - y);
		}
		cout << max(pmx - pmn, mmx - mmn) << endl;
	}
	return 0;
}