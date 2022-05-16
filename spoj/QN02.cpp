#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int f[100020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		f[F(x)] = F(y);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		puts(F(x) == F(y) ? "YES" : "NO");
	}
	return 0;
}