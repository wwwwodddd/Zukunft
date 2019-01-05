#include <bits/stdc++.h>
using namespace std;
int n, m, p = 1000000007;
int a[100020];
int c1[100020];
int c2[100020];
void change(int *c, int x, int y) {
	for (int i = x; i <= n; i += i & -i) {
		c[i] += y;
		if (c[i] >= p) {
			c[i] -= p;
		}
	}
}
int query(int *c, int x) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re += c[i];
		if (re >= p) {
			re -= p;
		}
	}
	return re;
}
int inv(int x) {
	if (x == 1) {
		return 1;
	}
	return (long long)(p - p / x) * inv(p % x) % p;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		change(c1, i, a[i]);
		int t2 = (long long)a[i] * a[i] % p;
		change(c2, i, t2);
	}
	for (int i = 0; i < m; i++) {
		int o, x, y;
		scanf("%d%d%d", &o, &x, &y);
		if (o == 1) {
			int t1 = -a[x];
			int t2 = -(long long)a[x] * a[x] % p;
			a[x] = y;
			t1 = (t1 + a[x]) % p;
			t2 = (t2 + (long long)a[x] * a[x]) % p;
			if (t1 < 0) {
				t1 += p;
			}
			if (t2 < 0) {
				t2 += p;
			}
			change(c1, x, t1);
			change(c2, x, t2);
		} else {
			int invlen = inv(y - x + 1);
			int t1 = query(c1, y) - query(c1, x - 1);
			int t2 = query(c2, y) - query(c2, x - 1);
			t1 = (long long)t1 * invlen % p;
			t2 = (long long)t2 * invlen % p;
			int ans = (t2 - (long long)t1 * t1) % p;
			if (ans < 0) {
				ans += p;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}