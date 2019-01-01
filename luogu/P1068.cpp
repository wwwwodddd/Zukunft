#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<int, int> a[100020];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].second, &a[i].first);
		a[i].first = -a[i].first;
	}
	sort(a, a + n);
	k = min(k * 3 / 2, n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (-a[i].first >= -a[k - 1].first) {
			cnt++;
		}
	}
	printf("%d %d\n", -a[cnt - 1].first, cnt);
	for (int i = 0; i < n; i++) {
		if (-a[i].first >= -a[k - 1].first) {
			printf("%d %d\n", a[i].second, -a[i].first);
		}
	}
	return 0;
}