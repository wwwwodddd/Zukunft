#include <bits/stdc++.h>
using namespace std;
int n, m, z;
string s[20];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < 1 << n; i++)
	{
		int c[26] = {};
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				for (int k = 0; k < s[j].size(); k++)
				{
					c[s[j][k] - 'a']++;
				}
			}
		}
		int t = 0;
		for (int j = 0; j < 26; j++)
		{
			if (c[j] == m)
			{
				t++;
			}
		}
		z = max(z, t);
	}
	cout << z << endl;
	return 0;
}
