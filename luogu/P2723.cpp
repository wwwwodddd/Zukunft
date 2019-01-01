#include <bits/stdc++.h>
using namespace std;
int k, n, a[100], b[100];
int q[100020];
int main() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	q[0] = 1;
	for (int i = 1; i <= n; i++) {
		int mn = 2147483647;
		for (int j = 0; j < k; j++) {
			mn = min(mn, a[j] * q[b[j]]);
		}
		q[i] = mn;
		for (int j = 0; j < k; j++) {
			if (a[j] * q[b[j]] == mn) {
				b[j]++;
			}
		}
	}
	cout << q[n] << endl;
}