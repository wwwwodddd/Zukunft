#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
char s[120][120];
bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '?') {
				s[i][j] = '0';
				for (int k = 0; k < 8; k++) {
					if (in(i + dx[k], j + dy[k])) {
						if (s[i + dx[k]][j + dy[k]] == '*') {
							s[i][j]++;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%s\n", s[i]);
	}
	return 0;
}