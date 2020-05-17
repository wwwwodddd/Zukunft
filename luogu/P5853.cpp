#include <bits/stdc++.h>
using namespace std;
int n, m, l, mod;
int a[45000] = {1};
int z[300];
void mul(int b)
{
	for (int i = 1; i < l; i++)
	{
		a[i] = (a[i] + a[i - 1]) % mod;
	}
	for (int i = l - 1; i >= b; i--)
	{
		a[i] = (a[i] + mod - a[i - b]) % mod;
	}
}
void div(int b)
{
	for (int i = b; i < l; i++)
	{
		a[i] = (a[i] + a[i - b]) % mod;
	}
	for (int i = l - 1; i > 0; i--)
	{
		a[i] = (a[i] + mod - a[i - 1]) % mod;
	}
}
int main()
{
	cin >> n >> m >> mod;
	l = n * (n - 1) / 2;
	for (int i = 1; i <= n; i++)
	{
		mul(i);
	}
	for (int j = 1; j < n; j++)
	{
		div(j + 1);
		for (int i = 0; i < n - j; i++)
		{
			z[i] = (z[i] + a[n * (n - 1) / 2 - m]) % mod;
			z[i + j] = (z[i + j] + a[m]) % mod;
		}
		mul(j + 1);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d%c", (z[i] + a[m]) % mod, i == n - 1 ? '\n' : ' ');
	}
	return 0;
}