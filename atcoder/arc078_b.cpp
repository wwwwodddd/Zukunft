#include <bits/stdc++.h>
using namespace std;
int n, x, y;
vector<int> a[100020];
int f[100020];
int g[100020];
void dfs(int x, int y)
{
	g[x] = g[y] + 1;
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
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	swap(f, g);
	dfs(n, 0);
	int c = 0;
	for (int i = 1; i <= n; i++)
	{
		if (f[i] > g[i])
		{
			c++;
		}
		else
		{
			c--;
		}
	}
	cout << (c < 0 ? "Fennec" : "Snuke") << endl;
	return 0;
}
