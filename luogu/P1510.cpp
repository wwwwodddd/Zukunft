#include <bits/stdc++.h>
using namespace std;
int n, m, c, x, y;
int f[10020];
int main()
{
	cin >> m >> n >> c;
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		for (int j = m; j >= 0; j--)
		{
			f[j] = min(f[j], f[max(j - x, 0)] + y);
		}
	}
	if (f[m] <= c)
	{
		cout << c - f[m] << endl;
	}
	else
	{
		cout << "Impossible" << endl;
	}
	return 0;
}