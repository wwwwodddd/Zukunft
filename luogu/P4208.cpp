#include <bits/stdc++.h>
using namespace std;
const int mod = 31011;
int n, m, v, w, z = 1;
map<int, vector<pair<int, int> > > e;
vector<pair<int, int> > a;
int f[105];
int F(int x)
{
	return f[x] != x ? F(f[x]) : x;
}
void dfs(int x,int y)
{
	if(x == a.size())
	{
		if (v < y)
		{
			v = y;
			w = 1;
		}
		else if (v == y)
		{
			w++;
		}
		return;
	}
	int xx = F(a[x].first);
	int yy = F(a[x].second);
	if (xx != yy)
	{
		if (rand() & 1)
		{
			swap(xx, yy);
		}
		f[xx] = yy;
		dfs(x + 1, y + 1);
		f[xx] = xx;
	}
	dfs(x + 1, y);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		e[z].push_back(make_pair(x, y));
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for(auto it = e.begin(); it != e.end(); it++)
	{
		a = it->second;
		v = w = 0;
		dfs(0, 0);
		z = z * w % mod;
		for (pair<int, int> j: a)
		{
			int x = F(j.first);
			int y = F(j.second);
			if (x != y)
			{
				f[x] = y;
				n--;
			}
		}
	}
	printf("%d\n", n > 1 ? 0 : z);
	return 0;
}