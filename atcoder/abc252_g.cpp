#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n;
int a[520];
int f[520][520];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = n; i > 0; i--)
	{
		for (int j = i; j <= n; j++)
		{
			f[i][j] = i < j ? f[i + 1][j] : 1;
			for (int k = i + 1; k < j; k++)
			{
				if (a[i + 1] < a[k + 1])
				{
					f[i][j] = (f[i][j] + (long long)f[i + 1][k] * f[k][j]) % p;		
				}
			}

		}
	}
	cout << f[1][n] << endl;
	return 0;
}
