#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[60], b[60], c[60], d[60];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> c[i] >> d[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int y = 1e9, z = 0;
		for (int j = 1; j <= m; j++)
		{
			if (y > abs(a[i] - c[j]) + abs(b[i] - d[j]))
			{
				y = abs(a[i] - c[j]) + abs(b[i] - d[j]);
				z = j;
			}
		}
		cout << z << endl;
	}
	return 0;
}
