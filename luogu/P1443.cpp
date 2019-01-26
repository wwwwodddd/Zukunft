#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int d[401][401];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool in(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
int main() {
	cin >> n >> m >> x >> y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = -1;
		}
	}
	d[x][y] = 0;
	queue<int> q;
	q.push(x);
	q.push(y);
	while (q.size()) {
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (in(nx, ny)) {
				if (d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(nx);
					q.push(ny);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%-5d", d[i][j]);
		}
		printf("\n");
	}
	return 0;
}