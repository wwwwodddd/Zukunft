#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[1020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i + 1;
	}
	sort(a, a + n);
	long long s = 0, t = 0;
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i].second);
		s += t;
		t += a[i].first;
	}
	printf("\n%.2f\n", (double)s / n);
	return 0;
}