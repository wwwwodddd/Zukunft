#include <bits/stdc++.h>
using namespace std;
int n, x, y;
pair<int, int> a[100020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		a[i].first = x - y;
		a[i].second = -x - y;
	}
	sort(a, a + n);
	int cnt = 0, l = -2e9;
	for (int i = 0; i < n; i++) {
		if (l < -a[i].second) {
			l = -a[i].second;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}