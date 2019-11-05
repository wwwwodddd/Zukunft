#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
double s;
long long n = 10000000000LL;
map<long long, double>g;
double F(long long x) {
	if (x == 0) {
		return 0;
	}
	double &t = g[x];
	if (t > 0) {
		return t;
	}
	t = (F((x - 1) / 2) + F(x - 1 - (x - 1) / 2)) + x;
	return t;
}
int main() {
	printf("%.15f\n", F(n) / n);
	for (long long i = 1; i < n; i++) {
		s += (s / i + i) * 2;
	}
	printf("%.15f\n", s / n / n + 1);
	printf("%.15f\n", s / n / n + 1 - F(n) / n);
	return 0;
}