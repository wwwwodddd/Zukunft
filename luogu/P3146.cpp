#include <bits/stdc++.h>
using namespace std;
int n, x, z;
int f[59][262146];
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		f[x][i] = i + 1;
	}
	for (int j = 2; j < 59; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (!f[j][i])
			{
				f[j][i] = f[j-1][f[j-1][i]];
			}
			if (f[j][i])
			{
				z = j;
			}
		}
	}
	printf("%d\n", z);
	return 0;
}