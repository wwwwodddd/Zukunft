#include <bits/stdc++.h>
using namespace std;
char s[40][40][40];
int d[40][40][40];
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
int n, m, l;
queue<int> q;
bool in(int x, int y, int z) {
	return 0 <= x && x < n && 0 <= y && y < m && 0 <= z && z < l;
}
int main() {
	scanf("%d%d%d", &n, &m, &l);
	memset(d, -1, sizeof d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%s", s[i][j]);
			for (int k = 0; k < l; k++) {
				if (s[i][j][k] == 'S') {
					d[i][j][k] = 0;
					q.push(i);
					q.push(j);
					q.push(k);
				}
			}
		}
	}
	int ans = -1;
	while (q.size()) {
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int z = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (in(nx, ny, nz) && s[nx][ny][nz] != '#') {
				if (d[nx][ny][nz] == -1) {
					d[nx][ny][nz] = d[x][y][z] + 1;
					if (s[nx][ny][nz] == 'E') {
						ans = d[nx][ny][nz];
					}
					q.push(nx);
					q.push(ny);
					q.push(nz);
				}
			}
		}
	}
	if (~ans) {
		printf("Escaped in %d minute(s).\n", ans);
	} else {
		printf("Trapped!\n");
	}
	return 0;
}