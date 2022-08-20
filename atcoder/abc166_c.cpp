#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, c;
int h[100020];
int v[100020];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		if (h[x] <= h[y])
		{
			v[x] = 1;
		}
		if (h[x] >= h[y])
		{
			v[y] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == 0)
		{
			c++;
		}
	}
	cout << c << endl;
	return 0;
}
