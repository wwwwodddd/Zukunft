#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200020];
int b[200020];
int c[200020];
bool ok(int m) {
	int kk = 0;
	multiset<int> s;
	for (int i = n - m; i < n; i++) {
		s.insert(a[i]);
	}
	for (int i = m - 1; i >= 0; i--) {
		if (s.lower_bound(b[i]) != s.end()) {
			s.erase(s.lower_bound(b[i]));
		} else if (s.lower_bound((b[i] + 1) / 2) != s.end()) {
			if (kk < k) {
				kk++;
				s.erase(s.lower_bound((b[i] + 1) / 2));
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
	return true;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	sort(a, a + n);
	sort(b, b + n);
	int L = 0, R = n + 1;
	while (L < R - 1) {
		int M = (L + R) / 2;
		if (ok(M)) {
			L = M;
		} else {
			R = M;
		}
	}
	printf("%d\n", L);
	return 0;
}