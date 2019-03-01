#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int d[40][40];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2, 2, 2, -2, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1, 2, -2, 2, -2};
bool in(int x, int y) {
	return 1 <= x && x < 40 && 1 <= y && y < 40;
}
int main() {
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			d[i][j] = -1;
		}
	}
	d[1][1] = 0;
	queue<int> q;
	q.push(1);
	q.push(1);
	while (q.size()) {
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		for (int i = 0; i < 12; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (in(nx, ny)) {
				if (d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(nx);
					q.push(ny);
				}
			}
		}
	}
	cin >> x >> y;
	cout << d[x][y] << endl;
	cin >> x >> y;
	cout << d[x][y] << endl;
	return 0;
}