#include <bits/stdc++.h>
using namespace std;
int n;
int pre[100020];
int in[100020];
int pos[100020];
void dfs(int prel, int prer, int inl, int inr)
{
	if (inl < inr)
	{
		int x = pre[prel];
		int lsz = pos[x] - inl;
		dfs(prel + 1, prel + 1 + lsz, inl, inl + lsz);
		dfs(prel + 1 + lsz, prer, inl + lsz + 1, inr);
		printf("%d ", x);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
		pos[in[i]] = i;
	}
	dfs(0, n, 0, n);
	return 0;
}