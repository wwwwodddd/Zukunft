#include <bits/stdc++.h>
using namespace std;
int n, m, x;
bitset<100000> f;
int main() {
	f[0] = true;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		f |= f << x;
	}
	for (int i = m; i >= 0; i--) {
		if (f[i]) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}