#include <bits/stdc++.h>
using namespace std;
int n;
double p[1000020];
int main() {
	double ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &p[i]);
		p[i] /= 1e6;
		ans = max(ans, (double)p[i]);
	}
	double f = 0;
	double g = 0;
	int j = 1;
	for (int i = 1; i <= n; i++) {
		while (j <= n && exp(f) * g < exp(f + log(1 - p[j])) * (g + p[j] / (1 - p[j]))) {
			f += log(1 - p[j]);
			g += p[j] / (1 - p[j]);
			j++;
		}
		ans = max(ans, exp(f) * g);
		f -= log(1 - p[i]);
		g -= p[i] / (1 - p[i]);
	}
	printf("%d\n", (int)(1000000 * ans));
}