#include <bits/stdc++.h>
using namespace std;
int n, m, s, x;
long long f[5555];
long long g[5555];
int q[5555], bb, ff;
int main()
{
	memset(f, 0xc0, sizeof f);
	f[0] = 0;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		bb = ff = 0;
		memcpy(g, f, sizeof g);
		memset(f, 0xc0, sizeof f);
		q[ff++] = m;
		for (int j = m; j > 0; j--)
		{
			while (bb < ff && q[bb] > j + s - 1)
			{
				bb++;
			}
			while (bb < ff && g[j - 1] >= g[q[ff - 1]])
			{
				ff--;
			}
			q[ff++] = j - 1;
			f[j] = g[q[bb]] + (long long)j * x;
		}
	}
	printf("%lld\n", *max_element(f, f + m + 1));
	return 0;
}