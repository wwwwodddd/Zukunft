#include <bits/stdc++.h>
using namespace std;
int f[1020];
int n, m;
int F(int x) {
	if (f[x] == x) {
		return x;
	}
	f[x] = F(f[x]);
	return f[x];
}
int main() {
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		cin >> m;
		for (int i = 1; i <= n; i++) {
			f[i] = i;
		}
		int cnt = n;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x = F(x);
			y = F(y);
			if (x != y) {
				f[x] = y;
				cnt--;
			}
		}
		cout << cnt - 1 << endl;
	}
	return 0;
}