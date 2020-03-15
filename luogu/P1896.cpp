#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
int s[90], a[90];
long long f[10][90][90], z;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < 1 << n; i++)
	{
		if ((i & (i >> 1)) == 0)
		{
			s[cnt] = i;
			a[cnt] = __builtin_popcount(i);
			cnt++;
		}
	}
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < cnt; j++)
		{
			for (int k = 0; k < cnt; k++)
			{
				if ((s[j] & (s[k] << 1)) == 0 && (s[j] & s[k]) == 0 && (s[j] & (s[k] >> 1)) == 0)
				{
					for (int l = a[j]; l <= m; l++)
					{
						f[i][j][l] += f[i-1][k][l-a[j]];
					}
				}
			}
			if (i == n)
			{
				z += f[i][j][m];
			}
		}
	}
	cout << z << endl;
	return 0;
}