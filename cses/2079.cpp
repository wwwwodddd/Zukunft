#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[200020];
int s[200020];
int f[200020];
void dfs(int x, int y, int d)
{
	s[x] = 1;
	f[x] = 0;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x, d + 1);
			s[x] += s[i];
			f[x] = max(f[x], s[i]);
		}
	}
	f[x] = max(f[x], n - s[x]);
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[y].push_back(x);
		a[x].push_back(y);
	}
	dfs(1, 0, 0);
	int z = 1;
	for (int i = 1; i <= n; i++)
	{
		if (f[z] > f[i])
		{
			z = i;
		}
	}
	cout << z << endl;
	return 0;
}