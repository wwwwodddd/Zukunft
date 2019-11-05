#include <bits/stdc++.h>
using namespace std;
long long f[20];
int n = 18;
long long dfs(int x, int y, long long z) {
	if (y > n) {
		return 0;
	}
	if (x == 10) {
		if (y == n) {
			return z;
		} else {
			return 0;
		}
	} else {
		long long ans = 0;
		for (int i = 0; i <= 3;i ++) {
			ans += dfs(x + 1, y + i, z / f[i]);
		}
		return ans;
	}
}
int main() {
	f[0] = 1;
	for (int i = 1; i < 20; i++) {
		f[i] = f[i - 1] * i;
	}
	cout << dfs(0, 0, f[n]) / 10 * 9 << endl;
	return 0;
}