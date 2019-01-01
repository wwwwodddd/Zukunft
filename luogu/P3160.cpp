#include <bits/stdc++.h>
using namespace std;
char s[9][9];
int n, m, p = 12345678, ans;
bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
long long f[30][1 << 8];
int a[9][9], b[256];
int dp() {
	int cnt = 0;
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(f, 0, sizeof f);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'X') {
				for (int dx = -1; dx <= 1; dx++) {
					for (int dy = -1; dy <= 1; dy++) {
						int x = i + dx;
						int y = j + dy;
						if (in(x, y)) {
							a[x][y] |= 1 << cnt;
						}
					}
				}
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 1 << cnt; k++) {
				if ((k & a[i][j]) == a[i][j]) {
					b[k]++;
				}
			}
		}
	}
	f[0][0] = 1;
	for (int i = 0; i < n * m; i++) {
		for (int j = 0; j < 1 << cnt; j++) {
			f[i + 1][j] += f[i][j] * (b[j] - i);
			f[i + 1][j] %= p;
			for (int k = 0; k < cnt; k++) {
				if (~j >> k & 1) {
					f[i + 1][j | 1 << k] += f[i][j];
					f[i + 1][j | 1 << k] %= p;
				}
			}
		}
	}
	return f[n * m][(1 << cnt) - 1];
}
void dfs(int x, int y, int t) {
	if (y == m) {
		dfs(x + 1, 0, t);
		return;
	}
	if (x == n) {
		ans += p + t * dp();
		ans %= p;
		return;
	}
	dfs(x, y + 1, t);
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (in(x + dx, y + dy) && s[x + dx][y + dy] == 'X') {
				return;
			}
		}
	}
	s[x][y] = 'X';
	dfs(x, y + 1, -t);
	s[x][y] = '.';
	return;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	dfs(0, 0, 1);
	printf("%d\n", ans);
	return 0;
}