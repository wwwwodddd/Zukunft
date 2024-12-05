#include <bits/stdc++.h>
using namespace std;
int f[10020];
int n, m, x, y, z;
int F(int x)
{
	if (f[x] == x)
	{
		return x;
	}
	f[x] = F(f[x]);
	return f[x];
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> z >> x >> y;
		if (z == 1)
		{
			f[F(x)] = F(y);
		}
		else
		{
			if (F(x) == F(y))
			{
				printf("Y\n");
			}
			else
			{
				printf("N\n");
			}
		}
	}
	return 0;
}