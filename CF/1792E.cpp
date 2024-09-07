#include <bits/stdc++.h>
using namespace std;
int t, n, m1, m2, z0, z1;
vector<pair<int, int> > a;
map<long long, long long> f;
void dfs(int x, long long y)
{
	if (x == a.size())
	{
		if (y <= n)
		{
			f[y] = y;
		}
		else
		{
			for (int i = 0; i < a.size(); i++)
			{
				if (y % a[i].first == 0)
				{
					f[y] = max(f[y], f[y / a[i].first]);
				}
			}
		}
		if (y / f[y] <= n)
		{
			z0++;
			z1 ^= y / f[y];
		}
		return;
	}
	for (int i = 0; i <= a[x].second; i++)
	{
		dfs(x + 1, y);
		y *= a[x].first;
	}
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		map<int, int> g;
		a.clear();
		f.clear();
		z0 = z1 = 0;
		cin >> n >> m1 >> m2;
		for (int i = 2; i * i <= m1 || i * i <= m2 ; i++)
		{
			while (m1 % i == 0)
			{
				g[i]++;
				m1 /= i;
			}
			while (m2 % i == 0)
			{
				g[i]++;
				m2 /= i;
			}
		}
		if (m1 > 1)
		{
			g[m1]++;
		}
		if (m2 > 1)
		{
			g[m2]++;
		}
		for (auto i : g)
		{
			a.push_back(i);
		}
		dfs(0, 1);
		cout << z0 << " " << z1 << endl;
	}
	return 0;
}