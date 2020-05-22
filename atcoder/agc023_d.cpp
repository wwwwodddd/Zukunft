#include <bits/stdc++.h>
using namespace std;
int n, s, l, r;
int x[100020];
long long p[100020];
long long z;
int main() {
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &p[i]);
	}
	for (int l = 0, r = n - 1; l <= r;) {
		if (x[l] >= s) {
			z += x[r] - s;
			break;
		}
		if (x[r] <= s) {
			z += s - x[l];
			break;
		}
		z += x[r] - x[l];
		if (p[l] >= p[r]) {
			while (l < r && p[l] >= p[r]) {
				p[l] += p[r--];
			}
		} else {
			while (l < r && p[l] < p[r]) {
				p[r] += p[l++];
			}
		}
	}
	printf("%lld\n", z);
	return 0;
}