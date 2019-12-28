#include <iostream>
#include <algorithm>
using namespace std;
int n;
pair<int, int>a[100];
int f[100];
long long g[100];
int main() {
	while(cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
			if (a[i].first > a[i].second) {
				swap(a[i].first, a[i].second);
			}
		}
		a[n++] = make_pair(20000, 30000);
		sort(a, a + n);
		for (int i = 0; i < n; i++) {
			f[i] = i;
			g[i] = 1;
			for (int j = 0; j < i; j++) {
				if (a[j].second <= a[i].first) {
					if (f[i] > f[j] + i - j - 1) {
						f[i] = f[j] + i - j - 1;
						g[i] = g[j];
					} else if (f[i] == f[j] + i - j - 1) {
						g[i] += g[j];
					}
				}
			}
		}
		cout << f[n - 1] << ' ' << g[n - 1] << endl;
	}
	return 0;
}