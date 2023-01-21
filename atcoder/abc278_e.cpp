#include <bits/stdc++.h>
using namespace std;
int n, m, l, h, w;
int a[320][320];
int c[320], d[320];
int cc, dc;
int main()
{
	cin >> n >> m >> l >> h >> w;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			dc += !d[a[i][j]]++;
		}
	}
	for (int i = 0; i <= n - h; i++)
	{
		memcpy(c, d, sizeof c);
		cc = dc;
		for (int j = 0; j < w; j++)
		{
			for (int k = i; k < i + h; k++)
			{
				cc -= !--c[a[k][j]];
			}
		}
		cout << cc;
		for (int j = w; j < m; j++)
		{
			for (int k = i; k < i + h; k++)
			{
				cc += !c[a[k][j - w]]++;
				cc -= !--c[a[k][j]];
			}
			cout << " " << cc;
		}
		cout << endl;
	}
	return 0;
}
