#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[50][50];
bool gao()
{
	for (int i1 = 0; i1 < n; i1++)
	{
		for (int i2 = i1 + 1; i2 < n; i2++)
		{
			for (int j1 = 0; j1 < m; j1++)
			{
				for (int j2 = j1 + 1; j2 < m; j2++)
				{
					if (a[i1][j1] + a[i2][j2] > a[i2][j1] + a[i1][j2])
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << (gao() ? "Yes" : "No") << endl;
	return 0;
}
