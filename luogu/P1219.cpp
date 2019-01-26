#include <bits/stdc++.h>
using namespace std;
int xplusy[30], xminusy[30], y[30], a[30];
int n, cnt;
void dfs(int x) {
	if (x == n) {
		if (cnt < 3) {
			for (int i = 0; i < n; i++) {
				cout << a[i];
				if (i == n - 1) {
					cout << endl;
				} else {
					cout << ' ';
				}
			}
		}
		cnt++;
		return;
	} else {
		for (int i = 1; i <= n; i++) {
			if (y[i] == 0 && xplusy[x + i] == 0 && xminusy[x - i + n] == 0) {
				a[x] = i;
				y[i] = 1;
				xplusy[x + i] = 1;
				xminusy[x - i + n] = 1;
				dfs(x + 1);
				xminusy[x - i + n] = 0;
				xplusy[x + i] = 0;
				y[i] = 0;
				a[x] = 0;
			}
		}
	}

}
int main() {
	cin >> n;
	dfs(0);
	cout << cnt << endl;
}