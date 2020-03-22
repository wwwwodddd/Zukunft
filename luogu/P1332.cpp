#include <bits/stdc++.h>
using namespace std;
int d[501][501];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m, A, B, x, y;
bool in(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &A, &B);
	queue<int> q;
	memset(d, -1, sizeof d);
	for (int i = 0; i < A; i++) {
		scanf("%d%d", &x, &y);
		d[x][y] = 0;
		q.push(x);
		q.push(y);
	}
	while (q.size()) {
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (in(nx, ny) ) {
				if (d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(nx);
					q.push(ny);
				}
			}
		}
	}
	for (int i = 0; i < B; i++) {
		scanf("%d%d", &x, &y);
		printf("%d\n", d[x][y]);
	}
	return 0;
}