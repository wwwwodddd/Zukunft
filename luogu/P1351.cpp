#include <bits/stdc++.h>
using namespace std;
int w[200020];
vector<int> a[200020];
int ans1, ans2, n, p = 10007;
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 0; j < a[i].size(); j++) {
			a[i][j] = w[a[i][j]];
			ans2 = (ans2 + sum * a[i][j]) % p;
			sum = (sum + a[i][j]) % p;
		}
		sort(a[i].begin(), a[i].end());
		if (a[i].size() >= 2) {
			ans1 = max(ans1, a[i][a[i].size() - 1] * a[i][a[i].size() - 2]);
		}
	}
	printf("%d %d\n", ans1, ans2 * 2 % p);
}