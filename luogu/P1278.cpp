#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[16];
int f[65537][16], z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		f[1 << i][i] = s[i].size();
		z = max(z, int(s[i].size()));
	}
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				for (int k = 0; k < n; k++)
				{
					if (~i >> k & 1)
					{
						if (s[j][s[j].size() - 1] == s[k][0])
						{
							f[i | 1 << k][k] = max(f[i | 1 << k][k], f[i][j] + int(s[k].size()));
							z = max(z, f[i | 1 << k][k]);
						}
					}
				}
			}
		}
	}
	cout << z << endl;
	return 0;
}
