#include <bits/stdc++.h>
using namespace std;
int a[4020][4020];
int v[16000000];
int C = 2010, cnt;
int n = 100000;
int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {0, -1, -1, 1, 1, 0};
vector<long long> z;

long long P(long long x) {
	if (x < 2) {
		return false;
	}
	for (long long i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	z.push_back(1);
	z.push_back(2);
	long long v = 8;
	for (int i = 2; i <= n; i++) {
		if (P(6 * i - 1) && P(6 * i + 1) && P(12 * i + 5)) {
			z.push_back(v);
		}
		v += i * 6;
	}

	v = 19;
	for (int i = 2; i <= n; i++) {
		if (P(6 * i - 1) && P(6 * i + 5) && P(12 * i - 7)) {
			z.push_back(v);
		}
//		cerr << "?? " << v << ' ' << 6 * i - 1 << ' ' << 6 * i + 5 << ' ' << 12 * i - 19 << endl;
		v += i * 6 + 6;
	}

	printf("%d\n", z.size());
	sort(z.begin(), z.end());
//	for (int i: z) {
//		printf("%d\n", i);
//	}
	printf("%d\n", z[10 - 1]);
	if (z.size() >= 2000) {
		printf("%lld\n", z[2000 - 1]);
	}
	return 0;
}