#include <bits/stdc++.h>
using namespace std;
char s[102][102];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y) {
	s[x][y] = '0';
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in(nx, ny) && s[nx][ny] != '0') {
			dfs(nx, ny);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] != '0') {
				ans++;
				dfs(i, j);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}