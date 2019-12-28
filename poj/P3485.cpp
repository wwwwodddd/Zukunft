#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
pair<double, double>a[100020];
int main() {
	int n, l, d;
	while (~scanf("%d%d%d", &l, &d, &n)) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			double r = sqrt(d * d - y * y);
			a[i] = make_pair(x - r, x + r);
		}
		sort(a, a + n);
		double p = -1e10;
		for (int i = 0; i < n; i++) {
			if (a[i].first > p) {
				p = a[i].second;
				ans++;
			}
			if (a[i].second < p) {
				p = a[i].second;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
