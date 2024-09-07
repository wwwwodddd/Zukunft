#include <bits/stdc++.h>
using namespace std;
int n, m;
bool f;
vector<pair<int, int> > a[100020];
bool v[100020];
int k[100020];
int b[100020];
int z[100020];
set<int> s;
set<int> c;
void dfs(int x)
{
	v[x] = true;
	c.insert(x);
	for (auto i : a[x])
	{
		if (!v[i.first])
		{
			k[i.first] = -k[x];
			b[i.first] = i.second - b[x];
			dfs(i.first);
		}
		else
		{
			if (k[i.first] + k[x] == 0 && b[i.first] + b[x] == i.second)
			{

			}
			else if (k[i.first] + k[x] == 0)
			{
				f = true;
			}
			else
			{
				s.insert((i.second - b[i.first] - b[x]) / (k[i.first] + k[x]));
			}
		}
	}
}
void gao()
{
	for (int i = 1; i <= n; i++)
	{
		if (!v[i])
		{
			s.clear();
			c.clear();
			k[i] = 1;
			b[i] = 0;
			dfs(i);
			if (f || s.size() > 1)
			{
				cout << "NO" << endl;
				return;
			}
			int x = 0;
			if (s.size() == 1)
			{
				x = *s.begin();
			}
			else
			{
				vector<int> d;
				for (int i : c)
				{
					d.push_back(-b[i] / k[i]);
				}
				sort(d.begin(), d.end());
				x = d[d.size() / 2];
			}
			for (int i : c)
			{
				z[i] = k[i] * x + b[i];
			}
		}
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << z[i] * 0.5 << " ";
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		a[x].push_back({y, z * 2});
		a[y].push_back({x, z * 2});
	}
	gao();
	return 0;
}