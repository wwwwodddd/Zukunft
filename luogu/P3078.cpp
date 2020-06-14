#include <bits/stdc++.h>
using namespace std;
int n, h, l;
long long z;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h);
		z += max(h - l, 0);
		l = h;
	}
	printf("%lld\n", z);
	return 0;
}