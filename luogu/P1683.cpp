#include <bits/stdc++.h>
using namespace std;
char s[50][50];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int dfs(int x, int y) {
	int re = 1;
	s[x][y] = '#';
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in(nx, ny) && s[nx][ny] != '#') {
			re += dfs(nx, ny);
		}
	}
	return re;
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '@') {
				printf("%d\n", dfs(i, j));
			}
		}
	}
	return 0;
}