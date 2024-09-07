#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
string s[1020];
string t[1020];
int a[1020][60];
int b[1020][60];
int D(char c)
{
	if (c == 'A')
	{
		return 0;
	}
	else if (c == 'C')
	{
		return 1;
	}
	else if (c == 'G')
	{
		return 2;
	}
	else if (c == 'T')
	{
		return 3;
	}
	else
	{
		assert(false);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < m; j++)
		{
			a[i][j] = D(s[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		for (int j = 0; j < m; j++)
		{
			b[i][j] = D(t[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			for (int k = j + 1; k < m; k++)
			{
				bool vis[64] = {};
				bool valid = true; 
				for (int l = 0; l < n; l++)
				{
					vis[16*b[l][i]+4*b[l][j]+b[l][k]] = true;
				}
				for (int l = 0; l < n; l++)
				{
					if (vis[16*a[l][i]+4*a[l][j]+a[l][k]])
					{
						valid = false;
						break;
					}
				}
				if (valid)
				{
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}