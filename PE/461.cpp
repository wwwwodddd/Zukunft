#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;


pair<double, pair<int, int> > a[120000000];
int c;
double pi = acos(-1.);
int n = 10000;
double F(int x) {
	return exp((double)x / n) - 1;
}
int main() {
	for (int i = 1; i < n * 3 / 2; i++) {
		for (int j = 1; j < i; j++) {
			a[c++] = make_pair(F(i) + F(j), make_pair(i, j));
		}
	}
	printf("A\n");
	sort(a, a + c);
	printf("B\n");
	int l = 0;
	int r = c - 1;
	pair<int, int> u, v;
	double ans = pi;
	while (l <= r) {
		if (a[l].first + a[r].first > pi) {
			if (ans > a[l].first + a[r].first - pi) {
				ans = a[l].first + a[r].first - pi;
				u = a[l].second;
				v = a[r].second;
			}
			r--;
		} else if (a[l].first + a[r].first < pi) {
			if (ans > pi - (a[l].first + a[r].first)) {
				ans = pi - (a[l].first + a[r].first);
				u = a[l].second;
				v = a[r].second;
			}
			l++;
		}
	}
	printf("%.15f\n", ans);
	printf("%d %d\n", u.first, u.second);
	printf("%d %d\n", v.first, v.second);
	printf("%d\n", u.first * u.first + u.second * u.second + v.first * v.first + v.second * v.second);
	return 0;
}