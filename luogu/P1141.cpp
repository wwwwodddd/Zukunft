#include <bits/stdc++.h>
using namespace std;
char s[1020][1020];
int a[1020][1020]; // a[i][j] (i, j)属于哪个连通块
int b[1000020]; // b[i] 第i个连通块的大小
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m, cnt;
bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int dfs(int x, int y) {
	int re = 1;
	a[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in(nx, ny) && a[nx][ny] == 0 && s[nx][ny] == s[x][y]) {
			re += dfs(nx, ny);
		}
	}
	return re;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2 == 1) {
				s[i][j] ^= 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				cnt++;
				b[cnt] = dfs(i, j);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", b[a[x - 1][y - 1]]);
	}
	return 0;
}