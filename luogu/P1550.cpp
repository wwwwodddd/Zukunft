#include <bits/stdc++.h>
using namespace std;
int n;
int a[320][320];
int d[320];
bool v[320];
int ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[n][i];
		a[i][n] = a[n][i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	n++;
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