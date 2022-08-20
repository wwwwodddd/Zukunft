#include <bits/stdc++.h>
using namespace std;
int n, m, q;
vector<int> a[150020];
set<int> s;
void dfs(int x, int k)
{
	s.insert(x);
	if (k == 0)
	{
		return;
	}
	for (int i : a[x])
	{
		dfs(i, k - 1);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x, k, z = 0;
		cin >> x >> k;
		s.clear();
		dfs(x, k);
		for (int i : s)
		{
			z += i;
		}
		cout << z << endl;
	}
	return 0;
}
