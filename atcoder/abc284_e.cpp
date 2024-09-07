#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
vector<int> a[200020];
int v[200020];
void dfs(int x)
{
	if (z == 1000000)
	{
		return;
	}
	z++;
	for (int i : a[x])
	{
		if (!v[i])
		{
			v[i] = 1;
			dfs(i);
			v[i] = 0;
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
	v[1] = 1;
	dfs(1);
	v[1] = 0;
	cout << z << endl;
	return 0;
}