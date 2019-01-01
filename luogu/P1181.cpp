#include <bits/stdc++.h>
using namespace std;
int n, m, s, x, z = 1;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (s + x > m) {
			z++;
			s = 0;
		}
		s += x;
	}
	printf("%d\n", z);
	return 0;
}