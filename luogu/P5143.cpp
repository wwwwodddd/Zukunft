#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n;
pair<double, pair<double, double> > a[50020];
double ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].Y.X >> a[i].Y.Y >> a[i].X;
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		double dx = a[i].X - a[i-1].X;
		double dy = a[i].Y.X - a[i-1].Y.X;
		double dz = a[i].Y.Y - a[i-1].Y.Y;
		ans += sqrt(dx * dx + dy * dy + dz * dz);
	}
	printf("%.3f\n", ans);
	return 0;
}