#include <bits/stdc++.h>
using namespace std;
int n, z;
int main() {
	scanf("%d", &n);
	for (int i = 1; n > 0; i++) {
		z += min(n, i) * i;
		n -= i;
	}
	printf("%d\n", z);
	return 0;
}