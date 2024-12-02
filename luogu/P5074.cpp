#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int s[13][13];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		unordered_map<int, long long> f[13][13];
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> s[i][j];
			}
		}
		f[0][0][0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				for (const auto &k : f[i][j])
				{
					int b = k.first;
					if (s[i][j] == 0)
					{
						if ((~b >> j & 1) && (~b >> (j + 1) & 1))
						{
							f[i][j + 1][b] += k.second;
						}
					}
					else
					{
						f[i][j + 1][b ^ (3 << j)] += k.second;
						if ((b >> j & 1) + (b >> (j + 1) & 1) == 1)
						{
							f[i][j + 1][b] += k.second;
						}
					}
				}
			}
			for (const auto &k : f[i][m])
			{
				int b = k.first;
				if (~b >> m & 1)
				{
					f[i + 1][0][k.first * 2] += k.second;
				}
			}
		}
		cout << f[n][0][0] << endl;
	}
	return 0;
}