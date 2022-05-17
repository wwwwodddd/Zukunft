#include <bits/stdc++.h>
using namespace std;
int n, z;
int v[20];
int a[20][20];
void dfs(int x, int y)
{
	if (x == n)
	{
		z = max(z, y);
	}
	else
	{
		for (int i = 0; i < 2 * n; i++)
		{
			if (v[i] == 0)
			{
				v[i] = 1;
				for (int j = i + 1; j < 2 * n; j++)
				{
					if (v[j] == 0)
					{
						v[j] = 1;
						dfs(x + 1, y ^ a[i][j]);
						v[j] = 0;
					}
				}
				v[i] = 0;
				break;
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
	{
		for (int j = i + 1; j < 2 * n; j++)
		{
			cin >> a[i][j];
		}
	}
	dfs(0, 0);
	cout << z << endl;
	return 0;
}