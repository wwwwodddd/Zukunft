#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[120][120];
int d[120][120][3];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct N {
	int d, x, y, c;
};
bool operator < (const N &a, const N &b) {
	return a.d > b.d;
}
priority_queue<N> q;
bool in(int x, int y) {
	return 1 <= x && x <= m && 1 <= y && y <= m;
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		scanf("%d", &a[x][y]);
		a[x][y]++;
	}
	memset(d, 0x3f, sizeof d);
	d[1][1][a[1][1]] = 0;
	q.push((N){0, 1, 1, a[1][1]});
	while (q.size() > 0) {
		N u = q.top();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = u.x + dx[k];
			int ny = u.y + dy[k];
			if (in(nx, ny)) {
				if (a[u.x][u.y] == 0 && a[nx][ny] == 0) {
					continue;
				}
				if (a[nx][ny] == 0) {
					if (d[nx][ny][u.c] > u.d + 2) {
						d[nx][ny][u.c] = u.d + 2;
						q.push((N){d[nx][ny][u.c], nx, ny, u.c});
					}
				} else {
					if (a[nx][ny] == u.c) {
						if (d[nx][ny][a[nx][ny]] > u.d) {
							d[nx][ny][a[nx][ny]] = u.d;
							q.push((N){d[nx][ny][a[nx][ny]], nx, ny, a[nx][ny]});
						}
					} else {
						if (d[nx][ny][a[nx][ny]] > u.d + 1) {
							d[nx][ny][a[nx][ny]] = u.d + 1;
							q.push((N){d[nx][ny][a[nx][ny]], nx, ny, a[nx][ny]});
						}
					}
				}
			}
		}
	}
	int ans = min(d[m][m][1], d[m][m][2]);
	if (ans > 1e9) {
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}