#include <bits/stdc++.h>
using namespace std;
char s[1000020];
int p[1000020];
int f[1000020];
int n;
long long z;
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	int u = 0;
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		while (u > 0 && s[u + 1] != s[i]) {
			u = p[u];
		}
		if (s[u + 1] == s[i]) {
			u++;
		}
		p[i] = u;
		f[i] = i;
		if (p[i] > 0)
		{
			f[i] = f[p[i]];
		}
		z += i - f[i];
	}
	printf("%lld\n", z);
	return 0;
}