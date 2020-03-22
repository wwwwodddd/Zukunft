#include <bits/stdc++.h>
using namespace std;
char s[2002][2002];
int d[2002][2002];
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
			char ch = s[nx][ny];
			if (in(nx, ny) && ch != '#') {
				if (d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					if (ch == 'd') {
						printf("%d\n", d[nx][ny]);
						return;
					}
					q.push(nx);
					q.push(ny);
				}
			}
		}
	}
	printf("No Way!\n");
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'm') {
				x = i;
				y = j;				
			}
		}
	}
	bfs(x, y);
	return 0;
}