#include <bits/stdc++.h>
using namespace std;
int n, cnt;
char s[500020];
int p[500020];
int f[500020];
int g[500020];
void gao(int *f) {
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
	for (int i = 1; i <= n; i++) {
		if (p[i] == 0 || i % (i - p[i]) > 0) {
			f[i] = 1;
		}
	}
}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	gao(f);
	if (f[n]) {
		printf("1\n1\n");
		return 0;
	}
	reverse(s + 1, s + 1 + n);
	gao(g);
	for (int i = 1; i <= n; i++) {
		if (f[i] && g[n - i]) {
			cnt++;
		}
	}
	if (cnt == 0) {
		printf("%d\n1\n", n);
	} else {
		printf("2\n%d\n", cnt);
	}
	return 0;
}