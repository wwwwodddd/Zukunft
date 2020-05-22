#include <bits/stdc++.h>
using namespace std;
pair<int, int> gao(pair<int, int> a, pair<int, int> b) {
	int c[] = {a.first, a.second, b.first, b.second};
	sort(c, c + 4);
	return {c[3], c[2]};
}
int n;
pair<int, int> a[262145];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 1 << n; i++) {
		scanf("%d", &a[i].first);
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 1 << n; i++) {
			if (i >> j & 1) {
				a[i] = gao(a[i], a[i ^ (1 << j)]);
			}
		}
	}
	for (int i = 1, z = 0; i < 1 << n; i++) {
		z = max(z, a[i].first + a[i].second);
		printf("%d\n", z);
	}
	return 0;
}