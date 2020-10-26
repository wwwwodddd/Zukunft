#include <bits/stdc++.h>
using namespace std;
string c, s;
int t[1020][26];
int f[1020];
int g[1020];
int main()
{
	cin >> c >> s;
	int n = c.size();
	int m = s.size();
	for (int i = 1; i <= m; i++)
	{
		int u = t[i - 1][s[i - 1] - 'a'];
		t[i - 1][s[i - 1] - 'a'] = i;
		for (int j = 0; j < 26; j++)
		{
			t[i][j] = t[u][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		memcpy(g, f, sizeof g);
		for (int j = 0; j < m; j++)
		{
			f[t[j][c[i] - 'a']] = max(f[t[j][c[i] - 'a']], g[j] + 1);
		}
	}
	printf("%d\n", n - *max_element(f, f + m));
	return 0;
}