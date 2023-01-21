#include <bits/stdc++.h>
using namespace std;
int m, n, c;
vector<pair<int, int> > a[100020];
vector<int> z, o;
int d[100020];
int e[100020];
int f[100020];
int v[100020];
int t[100020];
int x[100020];
int y[100020];
queue<int> q;
void dfs(int u)
{
	c++;
	d[u] = 0;
	for (pair<int, int> i: a[u])
	{
		if (v[i.second] == 0)
		{
			o.push_back(i.second);
			v[i.second] = 1;
			if (d[i.first] > 0)
			{
				dfs(i.first);
			}
		}
	}
}
void tree(int u)
{
	f[u] = 1;
	for (pair<int, int> i: a[u])
	{
		if (v[i.second] == 0)
		{
			if (f[i.first] == 0)
			{
				t[i.second] = 1;
				tree(i.first);
			}
		}
	}
}
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		cin >> x[i] >> y[i];
		a[x[i]].push_back(make_pair(y[i], i));
		a[y[i]].push_back(make_pair(x[i], i));
		d[x[i]]++;
		d[y[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 1)
		{
			q.push(i);
		}
	}
	while (q.size())
	{
		int u = q.front();
		q.pop();
		for (pair<int, int> i: a[u])
		{
			if (v[i.second] == 0)
			{
				d[u]--;
				assert(d[u] == 0);
				d[i.first]--;
				if (d[i.first] == 1)
				{
					q.push(i.first);
				}
				z.push_back(i.second);
				v[i.second] = 1;
				c++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] > 0)
		{
			tree(i);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (t[i] == 0 && v[i] == 0)
		{
			v[i] = 1;
			o.push_back(i);
			if (d[x[i]] > 0)
			{
				dfs(x[i]);
			}
		}
	}
	cout << m - c << endl;
	for (int i = 0; i < o.size(); i++)
	{
		cout << o[i] << endl;
	}
	for (int i = z.size() - 1; i >= 0; i--)
	{
		cout << z[i] << endl;
	}
	assert(o.size() + z.size() == m);
	int ans = 0;
	memset(d, 0, sizeof d);
	for (int i = 0; i < o.size(); i++)
	{
		if (d[x[o[i]]] == 0)
		{
			d[x[o[i]]] = 1;
			ans++;
		}
		else if (d[y[o[i]]] == 0)
		{
			d[y[o[i]]] = 1;
			ans++;
		}
	}
	for (int i = z.size() - 1; i >= 0; i--)
	{
		if (d[x[z[i]]] == 0)
		{
			d[x[z[i]]] = 1;
			ans++;
		}
		else if (d[y[z[i]]] == 0)
		{
			d[y[z[i]]] = 1;
			ans++;
		}
	}
	assert(ans == c);
	return 0;
}
