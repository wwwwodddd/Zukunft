#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n;
double a[100020];
int s[100020], ss;
long long xm(long long x1, long long y1, long long x2, long long y2) {
	return x1 * y2 - x2 * y1;
}
int main() {
	scanf("%d", &n);
	s[ss++] = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (i <= n) {
			scanf("%lf", &a[i]);
		}
		while (ss >= 2 && xm(s[ss - 1] - s[ss - 2], a[s[ss - 1]] - a[s[ss - 2]],
			i - s[ss - 2], a[i] - a[s[ss - 2]]) > 0) {
			ss--;
		}
		s[ss++] = i;
	}
	int t = 0;
	for (int i = 1; i <= n; i++) {
		while (i > s[t]) {
			t++;
		}
		ull res = (ull)a[s[t]] * (i - s[t - 1]) + (ull)a[s[t - 1]] * (s[t] - i);
		res *= 100000;
		res /= s[t] - s[t - 1];
		printf("%llu\n", res);
	}
	return 0;
}