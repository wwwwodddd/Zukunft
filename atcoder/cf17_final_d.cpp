#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[5020];
long long f[5020];
int n;
bool cmp(const pair<int, int> &a, pair<int, int> &b) {
	return a.first + a.second < b.first + b.second;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n, cmp);
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (f[j - 1] <= a[i].first) {
				f[j] = min(f[j], f[j - 1] + a[i].second);
			}
		}
	}
	for (int i = n; i >= 0; i--) {
		if (f[i] < 1e18) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}