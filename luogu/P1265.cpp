#include <bits/stdc++.h>
using namespace std;
int n;
double x[5020], y[5020];
double d[5020];
bool v[5020];
double ans;
double dist(int i, int j) {
	return hypot(x[i] - x[j], y[i] - y[j]);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i < n; i++) {
		d[i] = 1e30;
	}
	for (int i = 0; i < n; i++) {
		int mini = -1;
		double mind = 1e30;
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
				d[j] = min(d[j], dist(j, mini));
			}
		}
	}
	cout << fixed << setprecision(2) << ans << endl;
	return 0;
}