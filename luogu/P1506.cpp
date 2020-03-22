#include <bits/stdc++.h>
using namespace std;
char s[520][520];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
bool in(int x, int y) {
	return 0 <= x && x <= n + 1 && 0 <= y && y <= m + 1;
}

void dfs(int x, int y) {
	s[x][y] = '*';
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in(nx, ny) && s[nx][ny] != '*') {
			dfs(nx, ny);
		}
	}
}

int main() {
	scanf("%d%d", &n ,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1); // cin >> (s[i] + 1);
	}
	dfs(0, 0);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == '0') {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}