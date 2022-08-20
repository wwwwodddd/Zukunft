#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> b[200020];
int f[200020];
char o[200020];
int x[200020];
int d[200020];
int r[200020];
int e[200020][2];
int z[200020];
int ec;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y, int i)
{
	int fx = F(x);
	int fy = F(y);
	if (d[fx] != d[fy])
	{
		if (d[fx] == 0)
		{
			swap(fx, fy);
		}
		assert(d[fy] == 0 && d[fx] == 1);
		d[fx] = 0;
		for (int j: b[fx])
		{
			z[j] = i;
		}
	}
	if (fx != fy)
	{
		if (b[fx].size() > b[fy].size())
		{
			swap(fx, fy);
		}
		for (int j: b[fx])
		{
			b[fy].push_back(j);
		}
		b[fx].clear();
		f[fx] = fy;
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> o[i];
		if (o[i] == 'A')
		{
			ec++;
			cin >> e[ec][0] >> e[ec][1];
		}
		else
		{
			cin >> x[i];
			if (o[i] == 'R')
			{
				r[x[i]] = 1;
			}
			else // 'D'
			{
				d[x[i]] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		b[i].push_back(i);
		if (d[i] == 0)
		{
			z[i] = m;
		}
	}
	for (int i = 1; i <= ec; i++)
	{
		if (r[i] == 0)
		{
			U(e[i][0], e[i][1], m);
		}
	}
	for (int i = m - 1; i >= 0; i--)
	{
		if (o[i] == 'R')
		{
			U(e[x[i]][0], e[x[i]][1], i);
		}
		else if (o[i] == 'D')
		{
			int fx = F(x[i]);
			if (d[fx] == 1)
			{
				d[fx] = 0;
				for (int j: b[fx])
				{
					z[j] = i;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << z[i] << endl;
	}
	return 0;
}
