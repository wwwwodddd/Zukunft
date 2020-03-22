#include <bits/stdc++.h>
using namespace std;
int t, n;
long long s[200020];
long long e[200020];
long long d[200020];
bool ok(long long M) {
	long long re = 0;
	for (int i = 0; i < n; i++) {
		if (M >= s[i]) {
			re += (min(e[i], M) - s[i]) / d[i] + 1;
		}
	}
	return re % 2;
}
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld%lld%lld", &s[i], &e[i], &d[i]);
		}
		long long L = -1; // <=L的位置没有奇数个人 
		long long R = 1e10; // <= R的位置一定有奇数个人 
		if (!ok(R)) {
			cout << "Poor QIN Teng:(" << endl;
			continue;
		}
		while (L < R - 1) {
			long long M = (L + R) / 2;
			if (ok(M)) {
				R = M;
			} else {
				L = M;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] <= R && R <= e[i]) {
				if ((R - s[i]) % d[i] == 0) {
					cnt++;
				}
			}
		}
		cout << R << ' ' << cnt << endl;
	}
	return 0;
}