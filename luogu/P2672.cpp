#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100020];
int n;
int b[100020];
int h[100020];
int s[100020];
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].second);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
	}
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = n - 1; i >= 0; i--) {
		h[i] = max(h[i + 1], 2 * a[i].second + a[i].first);
	}
	for (int i = 0; i < n; i++) {
		b[i + 1] = max(b[i], a[i].second);
	}
	for (int i = 0; i < n; i++) {
		s[i + 1] = s[i] + a[i].first;
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", max(s[i] + h[i], s[i + 1] + 2 * b[i + 1]));
	}
	return 0;
}