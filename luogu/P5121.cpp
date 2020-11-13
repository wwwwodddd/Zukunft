#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, k;
char s[120][12];
bool v[120][12];
bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < 10;
}
int dfs(int x, int y, char c) {
	v[x][y] = true;
	int re = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in(nx, ny) && s[nx][ny] == c && !v[nx][ny]) {
			re += dfs(nx, ny, c);
		}
	}
	return re;
}
void color(int x, int y, char c) {
	s[x][y] = '0';
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in(nx, ny) && s[nx][ny] == c) {
			color(nx, ny, c);
		}
	}
}
bool gao() {
	bool flag = false;
	memset(v, 0, sizeof v);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (!v[i][j] && s[i][j] != '0') {
				int sz = dfs(i, j, s[i][j]);
				if (sz >= k) {
					flag = true;
					color(i, j, s[i][j]);
				}
			}
		}
	}
	return flag;
}
void fall() {
	for (int j = 0; j < 10; j++) {
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (s[i][j] != '0') {
				s[c++][j] = s[i][j];
			}
		}
		while (c < n) {
			s[c++][j] = '0';
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = n - 1; i >= 0; i--) {
		scanf("%s", s[i]);
	}
	while (gao()) {
		fall();
	}
	for (int i = n - 1; i >= 0; i--) {
		printf("%s\n", s[i]);
	}
	return 0;
}