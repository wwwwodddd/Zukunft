#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int x, y, d;
bool a[4020][4020];
long long n = 1e18;
int ans;
int z[100020];
int main() {
	x = y = 2010;
	for (int i = 1; i <= 20800 + n % 104; i++) {
		if (a[x][y]) {
			a[x][y] = 0;
			ans--;
			d = (d + 1) % 4;
			x += dx[d];
			y += dy[d];
		} else {
			a[x][y] = 1;
			ans++;
			d = (d + 3) % 4;
			x += dx[d];
			y += dy[d];
		}
		z[i] = ans;
	}
	cout << z[20800 + n % 104] + (n - 20800 - n % 104) / 104 * (z[20800] - z[20800 - 104]) << endl;
	return 0;
}