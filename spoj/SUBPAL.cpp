#include <bits/stdc++.h>
using namespace std;
int t;
char s[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%s", s);
		int b = 0, z = 0;
		map<int, int> g;
		g[b] = -1;
		for (int i = 0; s[i]; i++)
		{
			b ^= 1 << (s[i] - 'a');
			if (g.find(b) == g.end())
			{
				g[b] = i;
			}
			else
			{
				z = max(z, i - g[b]);
			}
			for (int j = 0; j < 26; j++)
			{
				if (g.find(b ^ (1 << j)) != g.end())
				{
					z = max(z, i - g[b ^ (1 << j)]);
				}
			}
		}
		printf("Case %d: %d\n", tt, z);
	}
	return 0;
}