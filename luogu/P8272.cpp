#include <bits/stdc++.h>
using namespace std;
int n, t, x, z;
pair<pair<int, int>, pair<int, int> > a[200020];
map<int, int> g;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first.second >> t >> x >> a[i].second.second;
		a[i].first.first = x + t;
		a[i].second.first = x - t;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (a[i].first.second == 1)
		{
			g[a[i].second.first] += a[i].second.second;
		}
		else
		{
			auto it = g.lower_bound(a[i].second.first);
			while (it != g.end())
			{
				int d = min(a[i].second.second, it->second);
				a[i].second.second -= d;
				it->second -= d;
				z += d;
				if (it->second == 0)
				{
					g.erase(it++);
				}
				else
				{
					break;
				}
			}
		}
	}
	cout << z << endl;
	return 0;
}