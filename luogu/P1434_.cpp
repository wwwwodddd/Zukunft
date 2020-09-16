#include <bits/stdc++.h>
using namespace std;
int f[120][120];
int a[120][120];
pair<int, int> b[10020];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			b[i * m + j] = make_pair(a[i][j], i * m + j);
		}
	}
	sort(b, b + n * m);
	int ans = 0;
	for (int i = 0; i < n * m; i++) {
		int x = b[i].second / m;
		int y = b[i].second % m;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (in(nx, ny) && a[x][y] > a[nx][ny]) {
				f[x][y] = max(f[x][y], f[nx][ny]);
			}
		}
		ans = max(ans, ++f[x][y]);
	}
	cout << ans << endl;
	return 0;
}