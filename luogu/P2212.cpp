#include <bits/stdc++.h>
using namespace std;
int n, c;
int x[2020], y[2020];
int d[2020];
bool v[2020];
int ans;
int dist(int i, int j) {
	int d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
	if (d < c) {
		return 1e9;
	} else {
		return d;
	}
}
int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
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
		if (mini == -1) {
			cout << -1 << endl;
			return 0;
		}
		ans += mind;
		v[mini] = true;
		for (int j = 0; j < n; j++) {
			if (!v[j]) {
				d[j] = min(d[j], dist(j, mini));
			}
		}
	}
	cout << ans << endl;
	return 0;
}