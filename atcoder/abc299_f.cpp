#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
string s;
int n, z;
int t[120][26];
int f[120][120];
int main()
{
	cin >> s;
	n = s.size();
	for (int i = 0; i < 26; i++)
	{
		t[n][i] = n + 1;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		memcpy(t[i], t[i + 1], sizeof t[i]);
		t[i][s[i] - 'a'] = i + 1;
	}
	for (int o = 1; o < n; o++)
	{
		memset(f, 0, sizeof f);
		f[0][o] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (f[i][j] > 0)
				{
					for (int k = 0; k < 26; k++)
					{
						if (t[i][k] <= o && t[j][k] <= n)
						{
							f[t[i][k]][t[j][k]] = (f[t[i][k]][t[j][k]] + f[i][j]) % p;
						}
					}
				}
			}
		}
		for (int i = o + 1; i <= n; i++)
		{
			z = (z + f[o][i]) % p;
		}
	}
	cout << z << endl;
	return 0;
}