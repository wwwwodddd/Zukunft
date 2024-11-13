#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[100020];
int p[100020];
int f[100020];
double k;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
pair<int, int> dfs(int x, int y)
{
	pair<int, int> u = make_pair(0, p[x]);
	for (int i : a[x])
	{
		if (i != y)
		{
			pair<int, int> v = dfs(i, x);
			u.first += max(v.first, v.second);
			u.second += v.first;
		}
	}
	return u;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		f[i] = i;
	}
	int u, v;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (F(x) != F(y))
		{
			a[x].push_back(y);
			a[y].push_back(x);
			f[F(x)] = F(y);
		}
		else
		{
			u = x;
			v = y;
		}
	}
	int z = max(dfs(u, -1).first, dfs(v, -1).first);
	scanf("%lf", &k);
	printf("%.1f\n", k * z);
	return 0;
}