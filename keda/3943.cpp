#include <bits/stdc++.h>
using namespace std;
int n;
int L[1000020];
int R[1000020];
void dfs(int x)
{
	if (L[x] != 0)
	{
		dfs(L[x]);
	}
	printf("%d ", x);
	if (R[x] != 0)
	{
		dfs(R[x]);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &L[i], &R[i]);
	}
	dfs(1);
	printf("\n");
	return 0;
}