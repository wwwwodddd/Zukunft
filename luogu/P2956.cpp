#include <bits/stdc++.h>
using namespace std;
int n, m, l, z, xa, ya, xb, yb;
int a[250][250];
int main()
{
	cin >> n >> m >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> xa >> ya >> xb >> yb;
		xb++;
		yb++;
		a[xa][ya]++;
		a[xa][yb]--;
		a[xb][ya]--;
		a[xb][yb]++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
			if (a[i][j])
			{
				z++;
			}
		}
	}
	cout << z << endl;
	return 0;
}