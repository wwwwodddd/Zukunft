#include <bits/stdc++.h>
using namespace std;
int n;
int L[1000020];
int R[1000020];
void dfs1(int x)
{
	printf("%d ", x);
	if (L[x] != 0)
	{
		dfs1(L[x]);
	}
	if (R[x] != 0)
	{
		dfs1(R[x]);
	}
}
void dfs2(int x)
{
	if (L[x] != 0)
	{
		dfs2(L[x]);
	}
	printf("%d ", x);
	if (R[x] != 0)
	{
		dfs2(R[x]);
	}
}
void dfs3(int x)
{
	if (L[x] != 0)
	{
		dfs3(L[x]);
	}
	if (R[x] != 0)
	{
		dfs3(R[x]);
	}
	printf("%d ", x);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &L[i], &R[i]);
	}
	dfs1(1);
	printf("\n");
	dfs2(1);
	printf("\n");
	dfs3(1);
	printf("\n");
	return 0;
}