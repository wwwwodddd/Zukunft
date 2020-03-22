#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100020];
int n, b[100020], ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		b[a[i].second] = i;
	}
	for (int i = 0; i < n; i++) {
		while (b[i] != i) {
			swap(b[i], b[b[i]]);
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}