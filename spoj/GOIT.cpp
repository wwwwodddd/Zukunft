#include <bits/stdc++.h>
using namespace std;
int t, n, m;
double f[1020][1020];
double p[6];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		f[0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				cin >> p[j];
			}
			for (int j = 0; j <= m; j++)
			{
				f[i][j] = f[i - 1][j] * (j < m ? 1 - p[5] : 1) + (j ? f[i - 1][j - 1] * p[5] : 0);
			}
		}
		cout << f[n][m] << endl;
	}
	return 0;
}