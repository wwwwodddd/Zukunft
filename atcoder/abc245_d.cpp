#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[220];
int b[220];
int c[220];
int main()
{
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i <= n + m; i++)
	{
		cin >> c[i];
	}
	for (int i = m; i >= 0; i--)
	{
		b[i] = c[i + n] / a[n];
		for (int j = 0; j <= n; j++)
		{
			c[i + j] -= a[j] * b[i];
		}
	}
	for (int i = 0; i <= m; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
