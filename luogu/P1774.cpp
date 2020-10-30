#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[500020];
int c[500020];
void change(int x, int y) {
	for (int i = x; i <= n; i += i & -i) {
		c[i] += y;
	}
}
int query(int x) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re += c[i];
	}
	return re;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i + 1;
	}
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += i - query(a[i].second);
		change(a[i].second, 1);
	}
	cout << ans << endl;
	return 0;
}