#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
map<ull, int> g[2];
int n, a[5];
long long z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &a[j]);
		}
		sort(a, a + 5);
		for (int j = 0; j < 32; j++)
		{
			ull r = 0;
			int c = 0;
			for (int k = 0; k < 5; k++)
			{
				if (j >> k & 1)
				{
					r = r * 1234567891 + a[k];
					c++;
				}
			}
			g[c & 1][r]++;
		}
	}
	for (pair<ull, int> i: g[0])
	{
		z += (long long)i.second * (i.second - 1) / 2;
	}
	for (pair<ull, int> i: g[1])
	{
		z -= (long long)i.second * (i.second - 1) / 2;
	}
	printf("%lld\n", z);
	return 0;
}