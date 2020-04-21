#include <bits/stdc++.h>
using namespace std;
int n;
int s[100020];
int c[100020], cc;
vector<int> a[100020];
vector<int> b[100020];
void dfs(int x, int y)
{
	s[x] = 1;
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			b[x].push_back(s[i]);
			s[x] += s[i];
		}
	}
	b[x].push_back(n - s[x]);
}
int ok(int l)
{
	if ((n - 1) % l != 0)
	{
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cc = 0;
		for (int j: b[i])
		{
			j %= l;
			if (j > 0)
			{
				c[cc++] = j;
			}
		}
		sort(c, c + cc);
		if (cc % 2 > 0)
		{
			return false;
		}
		for (int i = 0; i < cc; i++)
		{
			if (c[i] + c[cc - 1 - i] != l)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i < n; i++)
	{
		printf("%d", ok(i));
	}
	printf("\n");
	return 0;
}