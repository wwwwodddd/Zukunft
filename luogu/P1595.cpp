#include <bits/stdc++.h>
using namespace std;
long long f[25] = {1, 0};
int n;
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
	}
	printf("%lld\n", f[n]);
	return 0;
}