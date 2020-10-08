#include <bits/stdc++.h>
using namespace std;
int n, m, f[202][202];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> f[i][j];
			f[i][j] += max(max(f[i-1][j-1], f[i-1][j]), f[i-1][j+1]);
		}
	}
	cout << max(max(f[n][m/2], f[n][m/2+1]), f[n][m/2+2]) << endl;
	return 0;
}