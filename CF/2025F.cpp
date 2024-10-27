#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > a[300020];
vector<int> o[300020];
int f[300020];
int c[300020];
int x[300020];
int y[300020];
int z[300020];
int v[300020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void dfs(int x, int y)
{
	// cout << "dfs " << x << " " << y << endl;
	v[x] = 1;
	for (auto i : a[x])
	{
		if (i.first != y)
		{
			dfs(i.first, x);
			if (c[i.first])
			{
				if (i.second < m)
				{
					z[i.second] = 1;
				}
				else
				{
					z[i.second - m] = 0;
				}
				c[i.first] ^= 1;
			}
			else
			{
				if (i.second < m)
				{
					z[i.second] = 0;
				}
				else
				{
					z[i.second - m] = 1;
				}
				// cout << "xor " << x << " " << c[x] << " z[]=" << z[i.second] << " " << x << " " << i.second << endl;
				c[x] ^= 1;
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		int fx = F(x[i]);
		int fy = F(y[i]);
		if (fx != fy)
		{
			f[fx] = fy;
			a[x[i]].push_back(make_pair(y[i], i));
			a[y[i]].push_back(make_pair(x[i], i + m));
		}
		else
		{
			z[i] = 0;
			c[x[i]] ^= 1;
			o[x[i]].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == 0)
		{
			dfs(i, -1);
		}
	}
	memset(c, 0, sizeof c);
	for (int i = 0; i < m; i++)
	{
		if (z[i] == 0)
		{
			if (c[x[i]])
			{
				puts("x-");
			}
			else
			{
				puts("x+");
			}
			c[x[i]] ^= 1;
		}
		else
		{
			if (c[y[i]])
			{
				puts("y-");
			}
			else
			{
				puts("y+");
			}
			c[y[i]] ^= 1;
		}
	}
	return 0;
}