#include <bits/stdc++.h>
using namespace std;
double f[2520][2520];
int n, m, a[2520], s;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		s += a[i];
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = max(f[i + 1][j], (f[i + 1][j - 1] + f[i + 1][j] + a[i]) / 2);
		}
	}
	printf("%.6f\n", s - f[0][m]);
	return 0;
}