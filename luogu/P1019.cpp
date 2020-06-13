#include <bits/stdc++.h>
using namespace std;
int n, z;
string s[22];
int v[22], d[22][22];
void dfs(int x, int y)
{
	z = max(z, y);
	for (int i = 0; i < n; i++)
	{
		if (d[x][i] && v[i])
		{
			v[i]--;
			dfs(i, y + s[i].size() - d[x][i]);
			v[i]++;
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		cin >> s[i];
		v[i] = 2;
	}
	// s[n] = '$' + s[n];
	v[n] = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 1; k <= s[i].size() && k < s[j].size(); k++)
			{
				if (s[i].substr(s[i].size() - k, k) == s[j].substr(0, k))
				{
					d[i][j] = k;
					break;
				}
			}
		}
	}
	dfs(n, 1);
	cout << z << endl;
	return 0;
}