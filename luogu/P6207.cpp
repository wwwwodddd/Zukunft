#include <bits/stdc++.h>
using namespace std;
char s[120][120];
int d[120][120];
int px[120][120];
int py[120][120];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
void bfs(int x, int y) {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			d[i][j] = -1;
		}
	}
	d[x][y] = 0;
	q.push(x);
	q.push(y);
	while (q.size()) {
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (in(nx, ny) && s[nx][ny] != '*') {
				if (d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					px[nx][ny] = x;
					py[nx][ny] = y;
					q.push(nx);
					q.push(ny);
				}
			}
		}
	}
}
void dfs(int x, int y)
{
	if (x != 0 || y != 0)
	{
		dfs(px[x][y], py[x][y]);
	}
	printf("%d %d\n", x + 1, y + 1);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	int x, y;
	bfs(0, 0);
	dfs(n-1, m-1);
	return 0;
}