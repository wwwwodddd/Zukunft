#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, k, p, d;
vector<int> a[2020];
vector<int> b[2020];
int v[2020];
int z[2020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		z[i] = 1;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		queue<int> q;
		memset(v, -1, sizeof v);
		cin >> p >> d;
		v[p] = 0;
		q.push(p);
		while (q.size())
		{
			int u = q.front();
			q.pop();
			if (v[u] == d)
			{
				b[i].push_back(u);
			}
			else
			{
				z[u] = 0;
				for (int j : a[u])
				{
					if (v[j] == -1)
					{
						v[j] = v[u] + 1;
						q.push(j);
					}
				}
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		int s = 0;
		for (int j : b[i])
		{
			s += z[j];
		}
		if (s == 0)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for (int i = 1; i <= n; i++)
	{
		cout << z[i];
	}
	cout << endl;
	return 0;
}