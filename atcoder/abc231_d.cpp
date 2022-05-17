#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
int n, m, x, y;
int v[100020];
void dfs(int x, int y)
{
	if (v[x])
	{
		cout << "No" << endl;
		exit(0);
	}
	v[x] = 1;
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
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i].size() > 2)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!v[i])
		{
			dfs(i, 0);
		}
	}
	cout << "Yes" << endl;
	return 0;
}
