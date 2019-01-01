#include <bits/stdc++.h>
using namespace std;
int n, e, z;
pair<int, int> a[1000020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].second, &a[i].first);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (e <= a[i].second) {
			e = a[i].first;
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}