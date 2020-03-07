#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, x, y;
vector<int> a[100020];
long long f[100020][3];
void dfs(int x, int y)
{
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			f[x][0] = f[x][0] * (f[i][1] + f[i][2]) % mod;
			f[x][1] = f[x][1] * (f[i][2] + f[i][0]) % mod;
			f[x][2] = f[x][2] * (f[i][0] + f[i][1]) % mod;
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	fill(f[0], f[n + 1], 1);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		f[x][y % 3] = 0;
		f[x][y - 1] = 0;
	}
	dfs(1, 0);
	printf("%lld\n", (f[1][0] + f[1][1] + f[1][2]) % mod);
	return 0;
}