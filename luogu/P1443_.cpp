#include <bits/stdc++.h>
using namespace std;
int d[420][420];
int n, m, x, y;
int dx[] = {1, 2, -1, 2, 1, -2, -1, -2};
int dy[] = {2, 1, 2, -1, -2, 1, -2, -1};
bool in(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
int main() {
	cin >> n >> m >> x >> y;
	queue<int> q;
	q.push(x);
	q.push(y);
	memset(d, -1, sizeof d);
	d[x][y] = 0;
	while (q.size() > 0) {
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (in(nx, ny) && d[nx][ny] == -1) {
				d[nx][ny] = d[x][y] + 1;
				q.push(nx);
				q.push(ny);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%-5d", d[i][j]);
		}
		printf("\n"); 
	}
}