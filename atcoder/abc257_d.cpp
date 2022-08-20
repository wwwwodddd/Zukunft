#include <bits/stdc++.h>
using namespace std;
int n;
long long x[220];
long long y[220];
long long p[220];
long long d[220][220];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> p[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j]) + p[i] - 1) / p[i];
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
			}
		}
	}
	long long z = 1e18;
	for (int i = 0; i < n; i++)
	{
		z = min(z, *max_element(d[i], d[i] + n));
	}
	cout << z << endl;
	return 0;
}
