#include <bits/stdc++.h> 
using namespace std;
map<int, vector<pair<int, int> > > g;
int v[200020];
int n, m, p, e, z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> p >> e;
			g[p].push_back({e, i});
		}
	}
	for (auto i : g)
	{
		auto &b = i.second;
		sort(b.begin(), b.end());
		if (b.size() == 1 || b[b.size() - 1].first > b[b.size() - 2].first)
		{
			v[b[b.size() - 1].second] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		z += v[i];
	}
	if (z < n)
	{
		z++;
	}
	cout << z << endl;
	return 0;
}
