#include <bits/stdc++.h>
using namespace std;
int a[513][513];
int f[513][513];
int n;
int main()
{
	cin >> n;
	n = 1 << n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	memset(f, 0x3f, sizeof f);
	memset(f[0], 0, sizeof f[0]);
	int z = 1e9;
	for (int i = 0; i < n; i++)
	{
		int lb = i & -i;
		for (int j = 0; j < n; j++)
		{
			int s = j & (~ (lb - 1)) ^ lb;
			int e = s + lb;
			for (int k = s; k < e; k++)
			{
				f[i][j] = min(f[i][j], f[i - 1][k] + a[j][k]);
			}
			if (i == n - 1)
			{
				z = min(z, f[n - 1][j]);
			}
		}
	}
	cout << z << endl;
	return 0;
}
