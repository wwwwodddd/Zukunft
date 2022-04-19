#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[320];
long long f[320][320];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = m; k >= i - j - 1; k--)
			{
				f[i][k] = min(f[i][k], f[j][k - (i - j - 1)] + max(a[i] - a[j], 0));
			}
		}
	}
	cout << f[n + 1][m] << endl;
	return 0;
}