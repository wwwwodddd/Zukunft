#include <bits/stdc++.h>
using namespace std;
int n, r, q;
pair<int, int> a[200020], b[200020];
int w[200020];
int main() {
	scanf("%d%d%d", &n, &r, &q);
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &a[i].first);
		a[i].first = -a[i].first;
		a[i].second = i;
	}
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &w[i]);
	}
	sort(a, a + 2 * n);
	for (int _ = 0; _ < r; _++) {
		for (int i = 0; i < n; i++) {
			if (w[a[i * 2].second] < w[a[i * 2 + 1].second]) {
				a[i * 2 + 1].first--;
				b[i] = a[i * 2 + 1];
				b[i + n] = a[i * 2];
			} else {
				a[i * 2].first--;
				b[i] = a[i * 2];
				b[i + n] = a[i * 2 + 1];
			}
		}
		merge(b, b + n, b + n, b + 2 * n, a);
	}
	printf("%d\n", a[q - 1].second + 1);
	return 0;
}