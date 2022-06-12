#include <bits/stdc++.h>
using namespace std;
int n, q, x, y;
int w[100020];
int z[100020];
vector<int> a[100020];
vector<pair<int, int> > b[100020];
vector<int> dfs(int x, int y)
{
	vector<int> u;
	u.push_back(w[x]);
	for (int i : a[x])
	{
		if (i != y)
		{
			vector<int> v = dfs(i, x);
			copy(v.begin(), v.end(), back_inserter(u));
			inplace_merge(u.begin(), u.end() - v.size(), u.end(), greater<int>());
			u.resize(20);
		}
	}
	for (auto i : b[x])
	{
		z[i.second] = u[i.first - 1];
	}
	return u;
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &x, &y);
		b[x].push_back(make_pair(y, i));
	}
	dfs(1, 0);
	for (int i = 0; i < q; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}