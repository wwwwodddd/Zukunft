#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int f[1025];
char s[1025];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		memset(f, 0x3f, sizeof f);
		f[0] = 0;
		for (int i = 0; i < n; i++)
		{
			int b = 0;
			scanf("%s", s);
			for (int j = 0; j < m; j++)
			{
				b |= 1 << (s[j] - '0');
			}
			for (int j = 0; j < 1024; j++)
			{
				f[j | b] = min(f[j | b], f[j] + 1);
			}
		}
		printf("%d\n", f[1023] == 0x3f3f3f3f ? -1 : f[1023]);
	}
	return 0;
}