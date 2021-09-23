#include <bits/stdc++.h>
using namespace std;
int n, q, x, y;
vector<int> a[200020];
int z[200020];
void dfs(int x, int y)
{
	z[x] += z[y];
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x);
		}
	}
}
int main()
{
	cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y;
		z[x] += y;
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		cout << z[i] << ' ';
	}
	return 0;
}