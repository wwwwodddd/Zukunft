#include <bits/stdc++.h>
using namespace std;
vector<int> a[10000020];
int main() {
	int N = 10000000;
	int n = 110000000;
	n = 1000;
	N = n / 11;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			a[j].push_back(i);
		}
	}
	int z = 0;
	for (int k = 0; 12 * k + 8 <= n; k++) {
		for (int j = 0; j < a[k + 1].size(); j++) {
			double s = (8 * k + 5.0) * a[k + 1][j] * a[k + 1][j] + (3 * k + 2) + (k + 1) / a[k + 1][j];
			if (s <= n) {
				cerr << 3 * k + 2 << ' ' << (k + 1) / a[k + 1][j] << ' ' << (8 * k + 5LL) * a[k + 1][j] * a[k + 1][j] << endl;
				z++;
			}
		}
	}
	cout << z << endl;
	return 0;
}
