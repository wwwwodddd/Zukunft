#include <bits/stdc++.h>
using namespace std;
char s[500020];
int p;
int f[500020][2];
int g[500020][2];
void dfs()
{
	int x = p++;
	if (s[x] == '0')
	{
		f[x][0] = g[x][0] = 1;
	}
	else if (s[x] == '1')
	{
		int y = p;
		dfs();
		f[x][0] = f[y][1] + 1;
		f[x][1] = max(f[y][0], f[y][1]);
		g[x][0] = g[y][1] + 1;
		g[x][1] = min(g[y][0], g[y][1]);
	}
	else if (s[x] == '2')
	{
		int y = p;
		dfs();
		int z = p;
		dfs();
		f[x][0] = f[y][1] + f[z][1] + 1;
		f[x][1] = max(f[y][0] + f[z][1], f[y][1] + f[z][0]);
		g[x][0] = g[y][1] + g[z][1] + 1;
		g[x][1] = min(g[y][0] + g[z][1], g[y][1] + g[z][0]);
	}
}
int main()
{
	scanf("%s", s);
	dfs();
	printf("%d %d\n", max(f[0][0], f[0][1]), min(g[0][0], g[0][1]));
	return 0;
}