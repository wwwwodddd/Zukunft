#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int a[1020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		a[x] ^= 1;
		if (x == 1)
		{
			a[n] ^= 1;
		}
		else
		{
			a[x - 1] ^= 1;
		}
		if (x == n)
		{
			a[1] ^= 1;
		}
		else
		{
			a[x + 1] ^= 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}