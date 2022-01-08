#include <bits/stdc++.h>
using namespace std;
int n;
long long a[420];
long long f[420][420];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int i = n; i > 0; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			f[i][j] = 1e18;
			for (int k = i; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}
