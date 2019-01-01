#include <bits/stdc++.h>
using namespace std;
int n;
int a[120][120];
int d[120];
bool v[120];
int ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		d[i] = 1e9;
	}
	for (int i = 0; i < n; i++) {
		int mini = -1;
		int mind = 1e9;
		for (int j = 0; j < n; j++) {
			if (!v[j]) {
				if (mind > d[j]) {
					mind = d[j];
					mini = j;
				}
			}
		}
		ans += mind;
		v[mini] = true;
		for (int j = 0; j < n; j++) {
			if (!v[j]) {
				d[j] = min(d[j], a[j][mini]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}