#include <bits/stdc++.h>
using namespace std;
char s[1000020];
char t[1000020];
int p[1000020];
int z;
int main()
{
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	int n = strlen(s + 1);
	int m = strlen(t + 1);
	int u = 0;
	for (int i = 2; i <= m; i++)
	{
		while (u > 0 && t[u + 1] != t[i])
		{
			u = p[u];
		}
		if (t[u + 1] == t[i])
		{
			u++;
		}
		p[i] = u;
	}
	u = 0;
	for (int i = 1; i <= n; i++)
	{
		while (u > 0 && t[u + 1] != s[i])
		{
			u = p[u];
		}
		if (t[u + 1] == s[i])
		{
			u++;
		}
		if (u == m)
		{
			z++;
			u = p[u];
		}
	}
	printf("%d\n", z);
	return 0;
}