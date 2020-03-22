#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[100020];
pair<int, int> b[100020];
int r[100020];
int c[100020];
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
		a[i].second = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i].first);
		b[i].second = i;
	}
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		r[a[i].second] = b[i].second + 1;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += i - query(r[i]);
		change(r[i], 1);
	}
	cout << ans % 99999997 << endl;
	return 0;
}