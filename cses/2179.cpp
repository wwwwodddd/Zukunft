#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[100020];
int d[100020];
int v[100020];
vector<pair<int, int> > z;
void dfs(int x)
{
	v[x] = 1;
	for (int i : a[x])
	{
		if (v[i] == 0)
		{
			dfs(i);
			if (d[i])
			{
				z.push_back(make_pair(i, x));
				d[i] ^= 1;
			}
			else
			{
				z.push_back(make_pair(x, i));
				d[x] ^= 1;
			}
		}
		else if (v[i] == 2)
		{
			z.push_back(make_pair(x, i));
			d[x] ^= 1;
		}
	}
	v[x] = 2;
}
void loop()
{
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == 0)
		{
			dfs(i);
			if (d[i])
			{
				cout << "IMPOSSIBLE" << endl;
				return;
			}
		}
	}
	for (pair<int, int> i : z)
	{
		cout << i.first << " " << i.second << endl;
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	loop();
	return 0;
}