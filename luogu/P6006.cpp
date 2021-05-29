#include <bits/stdc++.h>
using namespace std;
int n, q;
int v[3000020];
int a[5020];
long long z[5020][5020];
int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			v[a[j] + 1000000] = 0;
		}
		for (int j = i - 1; j > 0; j--)
		{
			z[j][i] = z[j + 1][i] + z[j][i - 1] - z[j + 1][i - 1];
			if (1000000 - a[i] - a[j] >= 0)
			{
				z[j][i] += v[1000000 - a[i] - a[j]];
			}
			v[1000000 + a[j]]++;
		}
	}
	for (int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << z[l][r] << endl;
	}
	return 0;
}