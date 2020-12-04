#include <bits/stdc++.h>
using namespace std;
bitset<200> g[200];
int x[200];
int y[200];
int r[200];
int n, z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> r[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= r[i] * r[i])
			{
				g[i][j] = 1;
			}
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			if (g[i][k])
			{
				g[i] |= g[k];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		z = max(z, (int)g[i].count());
	}
	printf("%d\n", z);
	return 0;
}