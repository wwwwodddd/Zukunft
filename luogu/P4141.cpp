#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[2020];
int g[2020];
int a[2020];
int main()
{
	cin >> n >> m;
	f[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = m; j >= a[i]; j--)
		{
			f[j] = (f[j] + f[j - a[i]]) % 10;
		}
	}
	for (int i = 0; i < n; i++)
	{
		memcpy(g, f, sizeof f);
		for (int j = a[i]; j <= m; j++)
		{
			g[j] = (g[j] + 10 - g[j - a[i]]) % 10;
		}
		for (int j = 1; j <= m; j++)
		{
			cout << g[j];
		}
		cout << endl;
	}
	return 0;
}