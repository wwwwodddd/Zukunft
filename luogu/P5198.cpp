#include <bits/stdc++.h>
using namespace std;
char s[1002][1002];
bool v[1002][1002];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, area, perimeter;
pair<int, int> ans;
bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y) {
	if (v[x][y]) {
		return;
	}
	v[x][y] = true;
	area++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in(nx, ny) && s[nx][ny] == '#') {
			dfs(nx, ny);
		} else {
			perimeter++;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '#' && !v[i][j]) {
				area = 0;
				perimeter = 0;
				dfs(i, j);
				ans = max(ans, make_pair(area, -perimeter));
			}
		}
	}
	printf("%d %d\n", ans.first, -ans.second);
	return 0;
}