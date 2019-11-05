#include <bits/stdc++.h>
using namespace std;
vector<int> a[1000020];
int ans;
int cnt;
int main() {
	int n = 1000000;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			a[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j: a[i]) {
			int x = j;
			int y = i / j;
			if ((x + y) % 4 == 0 && (3 * x - y) > 0 && (3 * x - y) % 4 == 0) {
//				printf("%d %d %d\n", i, x, y);
				cnt++;
			}
		}
//			printf("%d %d\n", i, cnt);
		if (cnt == 10) {
			ans++;
//			printf("%d %d\n", i, cnt);
		}
	}
	printf("%d\n", ans);
	return 0;
}