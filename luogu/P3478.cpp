#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[1000020];
long long s[1000020];
long long f[1000020];
void dfs(int x, int y)
{
	s[x] = 1;
	f[x] = 0;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			s[x] += s[i];
			f[x] += f[i] + s[i];
		}
	}
}
void dfs2(int x, int y)
{
	for (int i : a[x])
	{
		if (i != y)
		{
			f[i] = f[x] - s[i] + (n - s[i]);
			dfs2(i, x);
		}
	}
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
	dfs2(1, 0);
	printf("%d\n", int(max_element(f, f + n + 1) - f));
	return 0;
}