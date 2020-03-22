#include <bits/stdc++.h>
using namespace std;
char s[1000020];
int p[1000020], n;
int main() {
	scanf("%d%s", &n, s + 1);
	int u = 0;
	for (int i = 2; i <= n; i++) {
		while (u > 0 && s[u + 1] != s[i]) {
			u = p[u];
		}
		if (s[u + 1] == s[i]) {
			u++;
		}
		p[i] = u;
	}
	printf("%d\n", n - p[n]);
}