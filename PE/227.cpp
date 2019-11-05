#include <bits/stdc++.h>
using namespace std;
const int n = 100;
int T(int x) {
	x = (x + n) % n;
	x = min(x, n - x);
	return x;
}
vector<double> gao(vector<double> f) {
	vector<double> g;
	g.resize(n / 2 + 1);
	g[0] = 0;
	for (int i = 1; i <= n / 2; i++) {
		g[i] = (18 * f[i] + 8 * f[T(i - 1)] + 8 * f[T(i + 1)] + f[T(i - 2)] + f[T(i + 2)]) / 36 + 1;
	}
	return g;
}
int main() {
	vector<double> f;
	f.resize(n / 2 + 1);
	for (int _ = 0; _ < 100000; _++) {
		f = gao(f);
		if (_ % 1000 == 0) {
			printf("%.12f\n", f[n / 2]);
		}
	}
	return 0;
}