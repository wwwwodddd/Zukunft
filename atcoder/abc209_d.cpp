#include <bits/stdc++.h>
using namespace std;
int n, q, x, y;
vector<int> a[100020];
int d[100020];
void dfs(int x, int y)
{
	d[x] = d[y] ^ 1;
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
	dfs(1, 0);
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y;
		cout << (d[x] ^ d[y] ? "Road" : "Town") << endl;
	}
	return 0;
}