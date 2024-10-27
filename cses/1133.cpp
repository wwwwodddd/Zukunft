#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[200020];
int s[200020];
long long f[200020];
void dfs(int x, int y)
{
	s[x] = 1;
	for (int i = 0; i < a[x].size(); i++)
	{
		if (a[x][i] != y)
		{
			dfs(a[x][i], x);
			s[x] += s[a[x][i]];
			f[x] += f[a[x][i]] + s[a[x][i]];
		}
	}
}
void sfd(int x, int y)
{
	for (int i = 0; i < a[x].size(); i++)
	{
		if (a[x][i] != y)
		{
			f[a[x][i]] += f[x] - (f[a[x][i]] + s[a[x][i]]) + (n - s[a[x][i]]);
			sfd(a[x][i], x);
		}
	}
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
	dfs(1, 0);
	sfd(1, 0);
	for (int i = 1; i <= n; i++)
	{
		printf("%lld ", f[i]);
	}
	return 0;
}