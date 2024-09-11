#include <bits/stdc++.h>
using namespace std;
int n, z, h, l;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h);
		z += max(h - l, 0);
		l = h;
	}
	printf("%d\n", z);
	return 0;
}