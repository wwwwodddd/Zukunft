#include <bits/stdc++.h>
using namespace std;
int n;
int a[3020];
long long f[3020][3020];
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
			f[i][j] = max(a[i] - f[i + 1][j], a[j] - f[i][j - 1]);
		}
	}
	cout << f[1][n] << endl;
	return 0;
}
