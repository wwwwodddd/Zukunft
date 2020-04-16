#include <bits/stdc++.h>
using namespace std;
int n, m;
long long d[10000];
bool v[10000];
long long get(long long x, long long y) {
	if (x > y) {
		swap(x, y);
	}
	return ((2019201913 * x + 2019201949 * y) % 2019201997);
}

int main() {
	cin >> n >> m;
	cout << (2019202081 - 48 * n - 84 * m) << endl;
	return 0;
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	for (int i = 1; i <= n; i++) {
		int mini = -1;
		long long mind = 1e18;
		for (int j = 1; j <= n; j++) {
			if (!v[j]) {
				if (mind > d[j]) {
					mind = d[j];
					mini = j;
				}
			}
		}
		v[mini] = true;
		for (int j = 1; j <= n; j++) {
			if (!v[j]) {
				d[j] = min(d[j], get(j, mini));
			}
		}
	}
	sort(d + 1, d + 1 + n);
	cout << d[n - m + 2] << endl;
	return 0;
}