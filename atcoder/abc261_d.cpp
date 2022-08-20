#include <bits/stdc++.h>
using namespace std;
int n, m, c, y;
int x[5020];
int b[5020];
long long f[5020][5020];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> c >> y;
		b[c] = y;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			f[i + 1][0] = max(f[i + 1][0], f[i][j]);
			f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + x[i + 1] + b[j + 1]);
		}
	}
	cout << *max_element(f[n], f[n] + n + 1) << endl;
	return 0;
}
