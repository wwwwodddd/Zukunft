#include <bits/stdc++.h>
using namespace std;
int t, n;
int x[2020];
int y[2020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i];
		}
		int z = 0;
		for (int i = 0; i < n; i++)
		{
			map<pair<int, int>, int> g;
			for (int j = 0; j < n; j++)
			{
				if (j == i)
				{
					continue;
				}
				int dx = x[j] - x[i];
				int dy = y[j] - y[i];
				int dg = __gcd(dx, dy);
				dx /= dg;
				dy /= dg;
				z += g[make_pair(-dy, dx)];
				z += g[make_pair(dy, -dx)];
				g[make_pair(dx, dy)]++;
			}
		}
		cout << z << endl;
	}
	return 0;
}