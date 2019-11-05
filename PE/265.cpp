#include <stdio.h>
#include <iostream>
using namespace std;
int n;
int v[100];
int mask;
long long z;
void dfs(int x, long long w) {
	if (x >= n) {
		if (v[w & mask] > 0) {
			return;
		}
		v[w & mask]++;
	}
	if (x == (1 << n)) {
		int flag = 1;
		for (int i = 1; i < 5; i++) {
			if (v[(w & ((1 << i) - 1)) << (5 - i)] > 0) {
				flag = 0;
			}
			v[(w & ((1 << i) - 1)) << (5 - i)]++;
		}
		if (flag == 1) {
			z += w;
			printf("%lld\n", w);
		}
		for (int i = 1; i < 5; i++) {
			v[(w & ((1 << i) - 1)) << (5 - i)]--;
		}
	} else {	
		dfs(x + 1, w * 2);
		if (x >= n) {
			dfs(x + 1, w * 2 + 1);
		}
	}
	if (x >= n) {
		v[w & mask]--;
	}
	return;
}
int main() {
	scanf("%d", &n);
	mask = (1 << n) - 1;
	dfs(0, 0LL);
	for (int i = 0; i < 1 << n; i++) {
		printf("%d %d\n", i, v[i]);
	}
	printf("%lld\n", z);
	return 0;
}