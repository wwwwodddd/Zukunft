#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int v[100000020];
int a[100000020];
int n = 100000000;
int m = 100000;
//int n = 1000;
//int m = 10;
int q[100000020];
int b, f;
long long ans;
int main() {
	for (int i = 2; i <= n; i++) {
		if (v[i] > 0) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			v[j] = i;	
	 	}
	}

	a[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (v[i] == v[i / v[i]]) {
			a[i] = 2 * a[i / v[i]] - a[i / v[i] / v[i]];
		} else {
			a[i] = 2 * a[i / v[i]];
		}
	}

	for (int i = 1; i <= n; i++) {
		while (b < f && a[q[f - 1]] < a[i]) {
			f--;
		}
		q[f++] = i;
		while (q[b] <= i - m) {
			b++;
		}
		if (i >= m) {
			ans += a[q[b]];
		}
	}
	printf("%lld\n", ans);
	return 0;
}
