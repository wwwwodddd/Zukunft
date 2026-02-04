#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
vector<int> a[1000020];
int f[1000020];
int g[1000020];
int s[1000020];
int b[1000020];
int z[1000020];
int t, n = 100000;
int main()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			a[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = (f[i] + 1) % p;
		for (int d : a[i])
		{
			f[i] = (f[i] + s[d]) % p;
		}

		for (int j = 0; j < a[i].size(); j++)
		{
			b[j] = 1;
			for (int d : a[a[i][j]])
			{
				b[j] = (b[j] + s[d]) % p;
			}
			b[j] = (b[j] - g[a[i][j]] + p) % p;
			g[a[i][j]] = (g[a[i][j]] + 2 * b[j] % p) % p;
		}
		for (int j = 0; j < a[i].size(); j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (a[i][j] % a[i][k] == 0)
				{
					b[j] = (b[j] - b[k] + p) % p;
				}
			}
		}
		for (int j = 0; j < a[i].size(); j++)
		{
			s[a[i][j]] = (s[a[i][j]] + 2 * b[j] % p) % p;
		}
		z[i] = (z[i - 1] + f[i]) % p;
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		printf("%d\n", z[n]);
	}
	return 0;
}
