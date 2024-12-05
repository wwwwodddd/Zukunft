#include <bits/stdc++.h>
using namespace std;
int t, n, m;
char s[60][60];
int f[60][60][5][2];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}
		memset(f, 0, sizeof f);
		if (s[1][0] != 'H')
		{
			f[1][0][0][0] = 1;
		}
		if (s[0][1] != 'H')
		{
			f[0][1][0][1] = 1;
		}
		for (int k = 0; k <= m; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i + 1 < n && s[i + 1][j] != 'H')
					{
						f[i + 1][j][k][0] += f[i][j][k][0];
						f[i + 1][j][k + 1][0] += f[i][j][k][1];
					}
					if (j + 1 < n && s[i][j + 1] != 'H')
					{
						f[i][j + 1][k][1] += f[i][j][k][1];
						f[i][j + 1][k + 1][1] += f[i][j][k][0];
					}
				}
			}
		}
		int s = 0;
		for (int k = 0; k <= m; k++)
		{
			s += f[n - 1][n - 1][k][0] + f[n - 1][n - 1][k][1];
			// cout << "DEBUG " << f[n - 1][n - 1][k][0] << " " <<  f[n - 1][n - 1][k][1] << endl;
		}
		cout << s << endl;
	}
	return 0;
}