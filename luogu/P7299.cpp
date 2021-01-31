#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
set<int> s[100020];
int p[100020];
int f[100020];
int n, m;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		p[i] = i;
		a[i].push_back(i);
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		swap(p[x], p[y]);
		a[p[x]].push_back(x);
		a[p[y]].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		f[F(i)] = F(p[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j: a[i])
		{
			s[F(i)].insert(j);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", int(s[F(i)].size()));
	}
	return 0;
}