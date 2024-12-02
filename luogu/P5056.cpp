#include <bits/stdc++.h>
using namespace std;
int t, n, m, ex, ey;
char s[13][13];
unordered_map<int, long long> f[13][13];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.')
			{
				ex = i;
				ey = j;
			}
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
				if (s[i][j] == '*')
				{
					if ((b >> (j * 2) & 3) == 0 && (b >> (j * 2 + 2) & 3) == 0)
					{
						f[i][j + 1][b] += k.second;
					}
				}
				else
				{
					if ((b >> (j * 2) & 3) == 0 && (b >> (j * 2 + 2) & 3) == 0)
					{
						f[i][j + 1][b ^ (9 << (j * 2))] += k.second;
					}
					else if ((b >> (j * 2) & 3) == 0 || (b >> (j * 2 + 2) & 3) == 0)
					{
						f[i][j + 1][b] += k.second;
						int p = (b >> (j * 2) & 3) + (b >> (j * 2 + 2) & 3);
						f[i][j + 1][b ^ ((5 * p) << (j * 2))] += k.second;
					}
					else
					{
						int d[13] = {};
						int p[13] = {};
						stack<int> t;
						for (int l = 0; l <= m; l++)
						{
							d[l] = (b >> (l * 2) & 3);
							if (d[l] == 1)
							{
								t.push(l);
							}
							else if (d[l] == 2)
							{
								p[l] = t.top();
								p[t.top()] = l;
								t.pop();
							}
						}
						if (d[j] == 2 && d[j + 1] == 1)
						{
							f[i][j + 1][b ^ (6 << (j * 2))] += k.second;
						}
						else if (d[j] == 1 && d[j + 1] == 1)
						{
							f[i][j + 1][b ^ (5 << (j * 2)) ^ (3 << (p[j + 1] * 2))] += k.second;
						}
						else if (d[j] == 2 && d[j + 1] == 2)
						{
							f[i][j + 1][b ^ (10 << (j * 2)) ^ (3 << (p[j] * 2))] += k.second;
						}
						else if (d[j] == 1 && d[j + 1] == 2)
						{
							if (i == ex && j == ey)
							{
								f[i][j + 1][b ^ (9 << (j * 2))] += k.second;
							}
						}
					}
				}
			}
		}
		for (const auto &k : f[i][m])
		{
			int b = k.first;
			if ((b >> (2 * m) & 3) == 0)
			{
				f[i + 1][0][k.first * 4] += k.second;
			}
		}
	}
	cout << f[n][0][0] << endl;
	return 0;
}