#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1020][1020];
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1++;
		y1++;
		x2++;
		y2++;
		a[x1][y1]++;
		a[x1][y2]--;
		a[x2][y1]--;
		a[x2][y2]++;
	}
	for (int i = 1; i <= 1010; i++) {
		for (int j = 1; j <= 1010; j++) {
			a[i][j] += a[i][j - 1];
		}
	}
	for (int i = 1; i <= 1010; i++) {
		for (int j = 1; j <= 1010; j++) {
			a[i][j] += a[i - 1][j];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 1010; i++) {
		for (int j = 1; j <= 1010; j++) {
			if (a[i][j] == k) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}