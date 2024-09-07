#include <bits/stdc++.h>
using namespace std;
int n;
long long q;
int d[120][120];
int l[120][120];
int f[120][120];
bool ok(int M)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int t = M / n + (i < M % n); 
			f[i][j] = max(d[i][j] - t, l[i][j]);
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	long long p = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p += f[i][j];
		}
	}
	return p <= q;
}
int main()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> d[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> l[i][j];
		}
	}
	int L = -1, R = 1e8;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		if (ok(M))
		{
			R = M;
		}
		else
		{
			L = M;
		}
	}
	if (R == 1e8)
	{
		R = -1;
	}
	cout << R << endl;
	return 0;
}
