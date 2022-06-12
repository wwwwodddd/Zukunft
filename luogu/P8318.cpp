#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[1020];
int k[220];
int x[220];
int y[220];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> k[i] >> x[i] >> y[i];
	}
	for (int i = m; i > 0; i--)
	{
		if (k[i] == 1)
		{
			if (x[i] == y[i])
			{
				a[x[i]] /= 2;
			}
			else
			{
				a[x[i]] -= a[y[i]];
			}
		}
		else
		{
			if (x[i] == y[i])
			{
				a[x[i]] = sqrt(a[x[i]]);
			}
			else
			{
				a[x[i]] /= a[y[i]];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
