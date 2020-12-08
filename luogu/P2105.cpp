#include <bits/stdc++.h>
using namespace std;
int xplusy[40020], xminusy[40020], r[40020], c[40020];
int n, m, l, x, y, z;
int main()
{
	cin >> n >> m >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> x >> y;
		r[x] = c[y] = xplusy[x + y] = xminusy[x - y + m] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (r[i])
		{
			continue;
		}
		for (int j = 1; j <= m; j++)
		{
			if (!c[j] && !xplusy[i + j] && !xminusy[i - j + m])
			{
				z++;
			}
		}
	}
	cout << z << endl;
	return 0;
}