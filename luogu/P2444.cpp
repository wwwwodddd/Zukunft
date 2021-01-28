#include <bits/stdc++.h>
using namespace std;
int n;
int t[30020][2], tt;
int v[30020];
int g[30020];
int q[30020], qq;
int in[30020];
char c[30020];
void ins(char *s)
{
	int p = 0;
	for (; *s; s++)
	{
		if (t[p][*s - '0'] == 0)
		{
			t[p][*s - '0'] = ++tt;
		}
		p = t[p][*s - '0'];
	}
	v[p] = 1;
}
bool dfs(int x)
{
	if (v[x])
	{
		return v[x] == 2;
	}
	v[x] = 2;
	if (dfs(t[x][0]) || dfs(t[x][1]))
	{
		return true;
	}
	v[x] = 1;
	return false;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", c);
		ins(c);
	}
	q[qq++] = 0;
	for (int j = 0; j < qq; j++)
	{
		int u = q[j];
		v[u] |= v[g[u]];
		for (int i = 0; i < 2; i++)
		{
			if (t[u][i])
			{
				g[t[u][i]] = u ? t[g[u]][i] : 0;
				q[qq++] = t[u][i];
			}
			else
			{
				t[u][i] = t[g[u]][i];
			}
		}
	}
	for (int i = 0; i <= tt; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			in[t[i][j]]++;
		}
	}
	puts(dfs(0) ? "TAK" : "NIE");
	return 0;
}