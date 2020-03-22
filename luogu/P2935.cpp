#include <bits/stdc++.h>
using namespace std;
int n, m, l, ans;
int a[10020];
int d[520][520];
int main() {
	cin >> n >> m >> l;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= n; i++) {
		d[i][i] = 0; // 自己到自己的距离必须初始化为0 
	}
	for (int i = 0; i < l; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		d[x][y] = d[y][x] = z; // 如果有重边不能直接赋值 
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int mindis = 1e9;
	int minindex = -1;
	for (int i = 1; i <= n; i++) {
		int dis = 0;
		for (int j = 0; j < m; j++) {
			dis += d[i][a[j]];
		}
		if (mindis > dis) {
			mindis = dis;
			minindex = i;
		}
	}
	cout << minindex << endl;
}