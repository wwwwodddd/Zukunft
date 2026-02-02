#include <bits/stdc++.h>
using namespace std;
const int p = 1000000009;
int n, m;
int pc[1048577];
int a[21][1048577];
int b[21][1048577];
int c[21][1048577];
void fmt(int a[], int d = 1)
{
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i >> j & 1)
			{
				a[i] = (a[i] + a[i ^ 1 << j] * d) % p;
				if (a[i] < 0)
				{
					a[i] += p;
				}
			}
		}
	}
}
int main()
{
	scanf("%d", &m);
	n = 1 << m;
	for (int i = 0; i < n; i++)
	{
		pc[i] = pc[i >> 1] + (i & 1);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[pc[i]][i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[pc[i]][i]);
	}
	for (int i = 0; i <= m; i++)
	{
		fmt(a[i]);
		fmt(b[i]);
	}
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; i + j <= m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				c[i + j][k] = (c[i + j][k] + (long long)a[i][k] * b[j][k]) % p;
			}
		}
	}
	for (int i = 0; i <= m; i++)
	{
		fmt(c[i], -1);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", c[pc[i]][i]);
	}
	printf("\n");
	return 0;
}