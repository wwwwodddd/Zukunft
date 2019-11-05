#include <iostream>
#include <cstdio>
using namespace std;
int a[4][4];
int s[4];
int ans;
int radix = 10;
void print() {
	printf("----------\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d%c", a[i][j], j == 3 ? '\n' : ' ');
		}
	}
}
void dfs(int x, int y) {
	if (x == 2 && y == 2) {
		if (a[0][0] + a[1][0] + a[2][0] != a[0][3] + a[1][2] + a[2][1]) {
			return;
		}
	}
	if (x == 3 && y == 0) {
		a[3][0] = s[0] - a[0][0] - a[1][0] - a[2][0];
		a[3][1] = s[0] - a[0][1] - a[1][1] - a[2][1];
		a[3][2] = s[0] - a[0][2] - a[1][2] - a[2][2];
		a[3][3] = s[0] - a[0][3] - a[1][3] - a[2][3];
		if (a[3][0] < 0 || a[3][0] >= radix) {
			return;
		}
		if (a[3][1] < 0 || a[3][1] >= radix) {
			return;
		}
		if (a[3][2] < 0 || a[3][2] >= radix) {
			return;
		}
		if (a[3][3] < 0 || a[3][3] >= radix) {
			return;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (a[i][j] < 0 || a[i][j] >= radix) {
					return;
				}
			}
		}

		if (a[0][0] + a[0][1] + a[0][2] + a[0][3] != s[0]) {
			return;
		}
		if (a[1][0] + a[1][1] + a[1][2] + a[1][3] != s[0]) {
			return;
		}
		if (a[2][0] + a[2][1] + a[2][2] + a[2][3] != s[0]) {
			return;
		}
		if (a[3][0] + a[3][1] + a[3][2] + a[3][3] != s[0]) {
			return;
		}

		if (a[0][0] + a[1][0] + a[2][0] + a[3][0] != s[0]) {
			return;
		}
		if (a[0][1] + a[1][1] + a[2][1] + a[3][1] != s[0]) {
			return;
		}
		if (a[0][2] + a[1][2] + a[2][2] + a[3][2] != s[0]) {
			return;
		}
		if (a[0][3] + a[1][3] + a[2][3] + a[3][3] != s[0]) {
			return;
		}

		if (a[0][0] + a[1][1] + a[2][2] + a[3][3] != s[0]) {
			return;
		}
		if (a[0][3] + a[1][2] + a[2][1] + a[3][0] != s[0]) {
			return;
		}
//		print();
		if (ans % 1000000 == 0) {
//			print();
			printf("%d\n", ans);
		}
		ans++;
		return;
	}
	if (x > 0 && y == 3) {
		a[x][y] = s[0] - a[x][0] - a[x][1] - a[x][2];
		if (a[x][y] < 0 || a[x][y] >= radix) {
			return;
		}
		s[x] = s[x - 1];
		dfs(x + 1, 0);
		return;
	}
	for (int i = 0; i < radix; i++) {
 		a[x][y] = i;
		if (y == 3) {
			s[x] = a[x][0] + a[x][1] + a[x][2] + a[x][3];
			if (x > 0 && s[x] != s[0]) {
				continue;
			}
			dfs(x + 1, 0);
		} else {
			dfs(x, y + 1);
		}
	}
}
int main() {
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}