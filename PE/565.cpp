#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> >z;
int v[1000020];
int p[100020], pc;
bool P(long long x) {
	for (int i = 0; (long long)p[i] * p[i] <= x; i++) {
		if (x % p[i] == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	long long n = 1e11;
	int d = 2017;
	for (int i = 2; i <= 1e6; i++) {
		if (v[i] > 0) {
			continue;
		}
		p[pc++] = i;
		for (int j = i; j <= 1e6; j += i) {
			v[j] = i;
		}
	}
	for (long long i = d; i <= n; i += d) {
		if (P(i - 1)) {
			z.push_back(make_pair(i - 1, i - 1));
		}
		if (i % 100000 == 0) {
			cerr << i << endl;
		}
	}
	cerr << z.size() << endl;
	return 0;
}