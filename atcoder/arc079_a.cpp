#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int v[200020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		if (x == 1)
		{
			v[y] |= 1;
		}
		if (y == n)
		{
			v[x] |= 2;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == 3)
		{
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
