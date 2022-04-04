#include <bits/stdc++.h>
using namespace std;
int t, n, m, l;
int f[60];
int d[60];
vector<int> a[60];
vector<int> c[60];
vector<int> p[60];
void hui()
{
	for (int i = 1; i <= n; i++)
	{
		a[i].clear();
		p[i].clear();
		f[i] = -1;
	}
	for (int i = 0; i < m; i++)
	{
		vector<int> s;
		for (int j = 0; j < c[i].size(); j++)
		{
			p[c[i][j]].push_back(i);
			if (s.size() > 0 && s.back() == c[i][j])
			{
				s.pop_back();
			}
			else
			{
				int nf = 0;
				if (s.size() > 0)
				{
					nf = s.back();
				}
				if (f[c[i][j]] != -1 && f[c[i][j]] != nf)
				{
					cout << "NO" << endl;
					return;
				}
				f[c[i][j]] = nf;
				if (j > 0 && c[i][j - 1] != f[c[i][j]])
				{
					a[c[i][j - 1]].push_back(c[i][j]);
				}
				s.push_back(c[i][j]);
			}
		}
		if (s.size() != 0)
		{
			cout << "NO" << endl;
			return;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < p[i].size(); j++)
		{
			if (p[i][j] > p[i][j - 1] + 1)
			{
				cout << "NO" << endl;
				return;
			}
		}
	}
	memset(d, 0, sizeof d);
	for (int i = 1; i <= n; i++)
	{
		for (int j: a[i])
		{
			d[j]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size() > 0)
	{
		int u = q.front();
		q.pop();
		for (int i: a[u])
		{
			if (!--d[i])
			{
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i])
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	return;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		memset(f, 0, sizeof f);
		for (int i = 0; i < m; i++)
		{
			cin >> l;
			c[i].resize(l);
			for (int j = 0; j < l; j++)
			{
				cin >> c[i][j];
			}
		}
		hui();
	}
	return 0;
}