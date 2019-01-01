#include <bits/stdc++.h>
using namespace std;
int n, k, s;
int main() {
	scanf("%d%d", &n, &k);
	s = n;
	while (__builtin_popcount(n) > k) {
		n += n & -n;
	}
	printf("%d\n", n - s);
	return 0;
}