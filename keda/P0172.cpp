#include <bits/stdc++.h>
using namespace std;
int n = 10, m = 3, sum;
int a[20];
int cnt;
int dijici;
void dfs(int x, int s) {
	if (x == n) {
		if (s == sum) {
			if (dijici == 1) {
				cnt++;
			} else {
				for (int i = 0; i < n; i++) {
					cout << a[i];
					if (i == n - 1) {
						cout << endl;
					} else {
						cout << ' ';
					}
				}
			}
		}
		return;
	}
	for (int j = 1; j <= m; j++) {
		a[x] = j;
		dfs(x + 1, s + j);
	}	
}
int main()
{
	cin >> sum;
	dijici = 1;
	dfs(0, 0);
	cout << cnt << endl;
	dijici = 2;
	dfs(0, 0);
}