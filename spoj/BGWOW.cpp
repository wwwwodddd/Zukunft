#include <bits/stdc++.h>
using namespace std;
int n, q, x, y, s;
vector<int> a[1020];
int L[1020];
int R[1020];
void dfs(int x, int y)
{
	L[x] = s++;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
		}
	}
	R[x] = s++;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d", &x, &y);
		printf("Case %d: %s\n", i, L[y] < L[x] && R[x] < R[y] ? "WOW" : "NO WAY");
	}
	return 0;
}