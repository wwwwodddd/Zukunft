#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200020][2];
int f[200020][2];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][0];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][1];
	}
	f[0][0] = f[0][1] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (f[i-1][k] && abs(a[i][j] - a[i-1][k]) <= m)
				{
					f[i][j] = 1;
				}
			}
		}
	}
	cout << (f[n-1][0] || f[n-1][1] ? "Yes" : "No") << endl;
	return 0;
}
