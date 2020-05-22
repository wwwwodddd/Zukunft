#include <bits/stdc++.h>
using namespace std;
int n, z;
pair<int, int> a[100020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if ((a[i].second + i) % 2 == 1) {
			z++;
		}
	}
	printf("%d\n", z / 2);
	return 0;
}