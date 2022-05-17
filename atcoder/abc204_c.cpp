#include <bits/stdc++.h>
using namespace std;
bitset<2000>d[2000];
int n, m, x, y, z;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		d[i][i] = 1;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		d[--x][--y] = 1;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (d[i][k]) {
				d[i] |= d[k];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		z += d[i].count();
	}
	cout << z << endl;
	return 0;
}
