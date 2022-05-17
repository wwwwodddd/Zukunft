#include <bits/stdc++.h>
using namespace std;
int n, m, u, z;
long long x;
vector<int> a[20];
void dfs(int d, long long x)
{
	if (d == n)
	{
		if (x == 1)
		{
			z++;
		}
		return;
	}
	for (int i: a[d])
	{
		if (x % i == 0)
		{
			dfs(d + 1, x / i);
		}
	}
}
int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> u;
			a[i].push_back(u);
		}
	}
	dfs(0, x);
	cout << z << endl;
	return 0;
}
