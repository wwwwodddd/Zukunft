#include <bits/stdc++.h>
using namespace std;
char t[1000020];
int p[1000020];
int main() {
	scanf("%s", t + 1);
	int m = strlen(t + 1);
	int u = 0;
	for (int i = 2; i <= m; i++) {
		while (u > 0 && t[u + 1] != t[i]) {
			u = p[u];
		}
		if (t[u + 1] == t[i]) {
			u++;
		}
		p[i] = u;
	}
	if (p[m] * 2 > m)
	{
		t[p[m] + 1] = 0;
		puts("YES");
		puts(t + 1);
	}
	else
	{
		puts("NO");
	}
	return 0;
}