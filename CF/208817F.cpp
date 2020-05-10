#include <bits/stdc++.h>
using namespace std;
int n, x, s;
vector<int> a[100020];
int v[100020];
int f[100020];
int main() {
	int n = 100000;
	for (int i = 1; i <= n; i++) {
		for (int j = i + i; j <= n; j += i) {
			a[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j: a[i]) {
			v[f[j]] = i;
		}
		while (v[f[i]] == i) {
			f[i]++;
		}
	}
	scanf("%d", &n);
	long long z = (long long)n * (n + 1) / 2;
	memset(v, 0, sizeof v);
	v[s]++;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		s ^= f[x];
		z -= v[s];
		v[s]++;
	}
	printf("%lld\n", z);
	return 0;
}