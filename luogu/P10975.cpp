#include <bits/stdc++.h>
using namespace std;
long long f[13][2049];
bool v[2049];
int n, m;
int main()
{
	v[0] = true;
	for (int i = 1; i < 1 << 11; i++)
	{
		if (i % 2 == 0)
		{
			v[i] = v[i / 2];
		}
		else if (i % 4 == 3)
		{
			v[i] = v[i / 4];
		}
		else
		{
			v[i] = false;
		}
	}
	while (cin >> n >> m, n + m)
	{
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 1 << m; j++)
			{
				if (f[i][j] == 0)
				{
					continue;
				}
				for (int k = 0; k < 1 << m; k++)
				{
					if ((j & k) == 0 && v[(1 << m) - 1 - j - k])
					{
						f[i + 1][k] += f[i][j];
					}
				}
			}
		}
		cout << f[n][0] << endl;
	}
	return 0;
}
