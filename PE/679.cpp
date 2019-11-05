#include <bits/stdc++.h>
using namespace std;
long long f[31][17][65];
int a[4] = {181, 141, 52, 214};
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < 64; i++)
	{
		f[3][0][i] = 1;
	}
	for (int i = 3; i < n; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 64; k++)
			{
				for (int l = 0; l < 4; l++)
				{
					int nk = k * 4 + l;
					int nj = j;
					for (int u = 0; u < 4; u++)
					{
						if (nk == a[u])
						{
							if (nj >> u & 1)
							{
								nj = -1;
							}
							else
							{
								nj |= 1 << u;
							}
						}
					}
					if (nj == -1)
					{
						continue;
					}
					f[i + 1][nj][nk % 64] += f[i][j][k];
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < 64; i++)
	{
		ans += f[n][15][i];
	}
	cout << ans << endl;
	return 0;
}
