#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
pair<pair<int, int>, int> a[320];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		a[i].first.first = x + y + z;
		a[i].first.second = x;
		a[i].second = -i;
	}
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < 5; i++) {
		printf("%d %d\n", -a[i].second + 1, a[i].first.first);
	}
	return 0;
}