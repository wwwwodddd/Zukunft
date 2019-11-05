#include <iostream>
#include <cstdio>
#include <cstring>
double f[52][32][32];
double ans[32][32];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
using namespace std;
bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}
void calc(int x, int y) {
	memset(f, 0, sizeof f);
	f[0][x][y] = 1;
	for (int k = 0; k < m; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int cnt = 0;
				for (int d = 0; d < 4; d++) {
					if (in(i + dx[d], j + dy[d])) {
						cnt++;
					}
				}
				for (int d = 0; d < 4; d++) {
					if (in(i + dx[d], j + dy[d])) {
						f[k + 1][i + dx[d]][j + dy[d]] += f[k][i][j] / cnt;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] *= 1 - f[m][i][j];
		}
	}
}
int main() {
	n = 30;
	m = 50;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			calc(i, j);	
		}
	}
	double xiaobeilou = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			xiaobeilou += ans[i][j];
		}
	}
	printf("%.6f\n", xiaobeilou);
	return 0;
}