#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	double x1, x2, y1, y2;
	scanf("%d", &n);
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	double l = 0, r = 1e17;
	for (int i = 0; i < n; i++) {
		double x, y, vx, vy;
		scanf("%lf%lf%lf%lf", &x, &y, &vx, &vy);
		{
			if (vx == 0) {
				if (x1 < x && x < x2) {

				} else {
					r = 0;
				}
			} else {
				double xt1 = (x1 - x) / vx;
				double xt2 = (x2 - x) / vx;
				double minxt1 = min(xt1, xt2);
				double maxxt1 = max(xt1, xt2);
				if (minxt1 < 0) {
					minxt1 = 0;
				}
				if (maxxt1 < 0) {
					maxxt1 = 0;
				}
				l = max(minxt1, l);
				r = min(maxxt1, r);
			}
		}
		{
			if (vy == 0) {
				if (y1 < y && y < y2) {

				} else {
					r = 0;
				}
			} else {
				double yt1 = (y1 - y) / vy;
				double yt2 = (y2 - y) / vy;
				double minyt1 = min(yt1, yt2);
				double maxyt1 = max(yt1, yt2);
				if (minyt1 < 0) {
					minyt1 = 0;
				}
				if (maxyt1 < 0) {
					maxyt1 = 0;
				}
				l = max(minyt1, l);
				r = min(maxyt1, r);
			}
		}
	}

	if (l >= r) {
		printf("-1\n");
	} else {
		printf("%.12f\n", l);
	}
}