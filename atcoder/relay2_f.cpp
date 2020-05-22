#include <bits/stdc++.h>
using namespace std;
int n;
long long x, px, s, f, z;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &x, &s);
		f = max(f + px - x + s, s);
		z = max(z, f);
		px = x;
	}
	printf("%lld\n", z);
	return 0;
}