#include <bits/stdc++.h>
using namespace std;
string s;
int f[320][320];
int g[320];
int lcp[320][320];
bool check(int i, int k)
{
	return lcp[i][i + k] >= k;
}
int main()
{
	cin >> s;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		for (int j = s.size() - 1; j >= 0; j--)
		{
			if (s[i] == s[j])
			{
				lcp[i][j] = lcp[i + 1][j + 1] + 1;
			}
			else
			{
				lcp[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		f[i][i + 1] = 1;
	}
	for (int l = 2; l <= s.size(); l++)
	{
		for (int i = 0; i + l <= s.size(); i++)
		{
			int j = i + l;
			f[i][j] = f[i][j - 1] + 1;
			if (l % 2 == 0 && check(i, l / 2))
			{
				f[i][j] = f[i][i + l / 2] + 1;
			}
		}
	}
	for (int j = 1; j <= s.size(); j++)
	{
		g[j] = g[j - 1] + 1;
		for (int i = 0; i < j; i++)
		{
			g[j] = min(g[j], g[i] + (i > 0) + f[i][j]);
		}
	}
	cout << g[s.size()] << endl;
	return 0;
}
