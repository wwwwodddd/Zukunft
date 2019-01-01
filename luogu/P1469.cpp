#include <bits/stdc++.h>
using namespace std;
int n, z, x;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		z ^= x;
	}
	printf("%d\n", z);
	return 0;
}
