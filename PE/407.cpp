#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[10000020];
int z[10000020];
int n = 10000000;
int main() {
	for (int i = 1; i <= n; i++) {
		if (i % 100000 == 0) {
			printf("%d\n", i);
		}
		z[i] = 0;
		for (int j = i; j <= n; j += i) {
			v[j].push_back(i);
		}
	}
	for (int i = 2; i <= n; i++) {
		if (i % 100000 == 0) {
			printf("%d\n", i);
		}
		for (int j = 0; j < v[i].size(); j++) {
			for (int k = 0; k < v[i - 1].size(); k++) {
				if ((long long)v[i][j] * v[i - 1][k] > i && (long long)v[i][j] * v[i - 1][k] <= n) {
					z[v[i][j] * v[i - 1][k]] = i;
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += z[i];
//		printf("%d %d\n", i, z[i]);
	}
	printf("%lld\n", ans);
	return 0;
}