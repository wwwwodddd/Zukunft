#include <bits/stdc++.h>
using namespace std;
int n;
int a[520][520];
int g[520][520];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		bool f = true;
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (f)
			{
				g[a[i][j]][i] = 1;
			}
			if (a[i][j] == i)
			{
				f = false;
			}
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				g[i][j] |= g[i][k] & g[k][j];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (g[i][a[i][j]])
			{
				cout << a[i][j] << endl;
				break;
			}
		}
	}
	return 0;
}