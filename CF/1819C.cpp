#include <bits/stdc++.h>
using namespace std;
int n, x, y, h, t;
vector<int> a[200020];
int f[200020];
int d[200020];
int v[200020];
vector<int> z;
void dfs(int x, int y)
{
	f[x] = y;
	d[x] = d[y] + 1;
	if (d[t] < d[x])
	{
		t = x;
	}
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	h = t;
	dfs(h, 0);
	for (;t > 0; t = f[t])
	{
		v[t] = 1;
		z.push_back(t);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!v[i] && !v[f[i]])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	for (int i = 0; i < z.size(); i++)
	{
		if (i & 1)
		{
			for (int j : a[z[i]])
			{
				if (!v[j])
				{
					cout << j << " ";
				}
			}
		}
		else
		{
			cout << z[i] << " ";
		}
	}
	for (int i = z.size(); i--;)
	{
		if (i & 1)
		{
			cout << z[i] << " ";
		}
		else
		{
			for (int j : a[z[i]])
			{
				if (!v[j])
				{
					cout << j << " ";
				}
			}
		}
	}
	cout << endl;
	return 0;
}