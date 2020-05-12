#include <bits/stdc++.h>
using namespace std;
const int mod = 100000000;
int n, m, x, ss;
int s[400], a[15];
int f[15][400];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < 1 << m; i++)
	{
		if ((i & (i >> 1)) == 0)
		{
			s[ss++] = i;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> x;
			a[i] |= x << j;
		}
	}
	f[0][0] = 1;
	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = 0; j < ss; j++)
		{
			if ((s[j] & a[i]) == s[j])
			{
				for (int k = 0; k < ss; k++)
				{
					if ((s[j] & s[k]) == 0)
					{
						f[i][j] = (f[i][j] + f[i-1][k]) % mod;
					}
				}
			}
		}
	}
	printf("%d\n", f[n + 1][0]);
	return 0;
}