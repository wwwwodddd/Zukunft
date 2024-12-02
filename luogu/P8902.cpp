#include <bits/stdc++.h>
using namespace std;
int n;
int a[320];
int r[320][320];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			scanf("%d", &r[i][j]);
		}
	}
	a[1] = 0;
	a[2] = r[1][2];
	int s = 1, j = 2;
	for (int i = 3; i <= n; i++)
	{
		if (r[j - 1][i] == r[j - 1][j] + r[j][i])
		{
			a[i] = a[i - 1] + s * r[i - 1][i];
		}
		else
		{
			s *= -1;
			a[i] = a[i - 1] + s * r[i - 1][i];
		}
		if (r[i - 1][i] > 0)
		{
			j = i;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d%c", a[i], i == n ? '\n' : ' ');
	}
	return 0;
}