#include <bits/stdc++.h>
using namespace std;
char s[1002][1002];
int d[1002][1002];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n;
bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}
void bfs(int x, int y) {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = -1;
		}
	}
	d[x][y] = 0;
	q.push(x);
	q.push(y);
	while (q.size()) {
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			char ch = s[nx][ny];
			if (in(nx, ny) && ch != '1') {
				if (d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(nx);
					q.push(ny);
				}
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	int x, y;
	cin >> x >> y;
	x--;
	y--;
	bfs(x, y);
	cin >> x >> y;
	x--;
	y--;
	cout << d[x][y] << endl;
	return 0;
}