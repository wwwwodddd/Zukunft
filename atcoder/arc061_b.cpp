#include <bits/stdc++.h>
using namespace std;
int h, w, n, x, y;
long long c[10];
map<pair<int, int>, int> g;
int main() {
	scanf("%d%d%d", &h, &w, &n);
	c[0] = (long long)(h - 2) * (w - 2);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		for (int j = x; j < x + 3; j++) {
			for (int k = y; k < y + 3; k++) {
				if (3 <= j && j <= h && 3 <= k && k <= w) {
					c[g[make_pair(j, k)]]--;
					c[++g[make_pair(j, k)]]++;
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%lld\n", c[i]);
	}
	return 0;
}