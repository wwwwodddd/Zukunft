#include <bits/stdc++.h>
using namespace std;
int a[10][10];
bool r[10][10];
bool c[10][10];
bool b[3][3][10];
void dfs(int x, int y) {
	if (y == 9) {
		dfs(x + 1, 0);
	}
	if (x == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d%c", a[i][j], j == 8 ? '\n' : ' ');
			}
		}
		exit(0);
	}
	if (a[x][y] > 0) {
		dfs(x, y + 1);
	} else {
		for (int i = 1; i <= 9; i++) {
			if (!r[x][i] && !c[y][i] && !b[x/3][y/3][i]) {
				r[x][i] = c[y][i] = b[x/3][y/3][i] = true;
				a[x][y] = i;
				dfs(x, y + 1);
				a[x][y] = 0;
				r[x][i] = c[y][i] = b[x/3][y/3][i] = false;
			}
		}
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] > 0) {
				r[i][a[i][j]] = true;
				c[j][a[i][j]] = true;
				b[i/3][j/3][a[i][j]] = true;
			}
		}
	}
	dfs(0, 0);
	return 0;
}