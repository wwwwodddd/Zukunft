#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[20020]; 
int f[20020][3];
int n, up, down;
void dfs(int x, int y) {
	f[x][0] = 1;
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i].first != y) {
			dfs(a[x][i].first, x);
			for (int j = 0; j < 3; j++) {
				up += f[x][j] * f[a[x][i].first][(6 - j - a[x][i].second) % 3];
			}
			for (int j = 0; j < 3; j++) {
				f[x][(j + a[x][i].second) % 3] += f[a[x][i].first][j];
			}
		}
	}
}
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z % 3));
		a[y].push_back(make_pair(x, z % 3));
	}
 	dfs(1, 0);
	up = up * 2 + n;
	down = n * n;
	int g = gcd(up, down);
	up /= g;
	down /= g;
	printf("%d/%d\n", up, down);
	return 0 ;
}