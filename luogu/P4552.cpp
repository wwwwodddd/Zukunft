#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100020];
long long pos, neg;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) {
			if (a[i] > a[i - 1]) {
				pos += a[i] - a[i - 1];
			} else {
				neg += a[i] - a[i - 1];
			}
		}
	}
	cout << max(pos, -neg) << endl << abs(a[0] - a[n-1]) + 1 << endl;
	return 0;
}