#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n = 12;

bool check(long long t, int b) {
	bool v[12] = {};
	while (t > 0) {
		v[t % b] = true;
		t /= b;
	}

	for (int i = 0; i < b; i++) {
		if (!v[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int a[12] = {};
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	long long cnt = 0;
	long long ans = 0;
	long long anscnt = 0;
	do {
		cnt++;
		if (a[0] == 0) {
			continue;
		}
		long long t = 0;
		for (int i = 0; i < n; i++) {
			t = t * n + a[i];
		}
		bool flag = true;
		for (int i = n - 1; i > 1; i--) {
			if (!check(t, i)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ans += t;
			anscnt++;
			cout << t << ' ' << anscnt << endl;
			if (anscnt == 10) {
				break;
			}
		}
		if (cnt % 10000000 == 0) {
			cout << cnt << endl;
		}
	} while (next_permutation(a, a + n));
	cout << ans << endl;
	return 0;
}