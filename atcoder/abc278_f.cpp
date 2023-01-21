#include <bits/stdc++.h>
using namespace std;
int n;
string s[20];
int f[65537][17];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 1 << n; i--;)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				for (int k = 0; k < n; k++)
				{
					if (~i >> k & 1 && s[j].back() == s[k][0])
					{
						f[i][j] |= !f[i | 1 << k][k];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!f[1 << i][i])
		{
			cout << "First" << endl;
			return 0;
		}
	}
	cout << "Second" << endl;
	return 0;
}
