#include <bits/stdc++.h>
using namespace std;
string s, t;
int f[300020];
int g[300020];
int main()
{
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	f[0] = 1;
	for (int i = 0; i < m; i++)
	{
		f[i + 1] = f[i];
		if (s[i] != '?' && t[i] != '?' && s[i] != t[i])
		{
			f[i + 1] = 0;
		}
	}
	g[0] = 1;
	for (int i = 0; i < m; i++)
	{
		g[i + 1] = g[i];
		if (s[s.size() - 1 - i] != '?' && t[t.size() - 1 - i] != '?' && s[s.size() - 1 - i] != t[t.size() - 1 - i])
		{
			g[i + 1] = 0;
		}
	}
	for (int i = 0; i <= m; i++)
	{
		cout << (f[i] && g[m - i] ? "Yes" : "No") << endl;
	}
	return 0;
}