#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[300020];
int f[300020];
int z;
void dfs(int x, int y)
{
	int c = 0, mx0 = 0, mx1 = 0;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			c++;
			if (mx0 < f[i])
			{
				mx1 = mx0;
				mx0 = f[i];
			}
			else if (mx1 < f[i])
			{
				mx1 = f[i];
			}
		}
	}
	f[x] = mx0 + max(1, c);
	z = max(z, mx0 + mx1 + max(1, int(a[x].size()) - 1));
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	printf("%d\n", z);
	return 0;
}