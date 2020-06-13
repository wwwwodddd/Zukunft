#include <bits/stdc++.h>
using namespace std;
char s[302][302];
int d[302][302];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int tx[256];
int ty[256];
int n, m;
bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
int bfs(int x, int y) {
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
				if (isalpha(ch)) {
					nx ^= tx[ch];
					ny ^= ty[ch];
				}
				if (d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					if (s[nx][ny] == '=') {
						return d[nx][ny];
					}
					q.push(nx);
					q.push(ny);
				}
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	int sx = -1;
	int sy = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '@') {
				s[i][j] = '.';
				sx = i;
				sy = j;
			}
			if (isalpha(s[i][j])) {
				tx[s[i][j]] ^= i;
				ty[s[i][j]] ^= j;
			}
		}
	}
	printf("%d\n", bfs(sx, sy));
	return 0;
}