#include <bits/stdc++.h>
using namespace std;
int n, m;
double x[1020], y[1020];
double a[1020][1020];
double d[1020];
bool v[1020];
double ans;
double dist(int i, int j) {
	return hypot(x[i] - x[j], y[i] - y[j]);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = dist(i, j);
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		a[x][y] = a[y][x] = 0;
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
				d[j] = min(d[j], a[j][mini]);
			}
		}
	}
	cout << fixed << setprecision(2) << ans << endl;
	return 0;
}