#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, t, u, v, w;
int a[300][300];
int work()
{
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			while (a[j][i])
			{
				int t = a[i][i] / a[j][i];
				for (int k = 1; k < n; k++)
				{
					a[i][k] = (a[i][k] - (long long)a[j][k] * t) % mod;
				}
				swap(a[i], a[j]);
				ans = -ans;
			}
		}
		ans = (long long)ans * a[i][i] % mod;
	}
	return (ans + mod) % mod;
}
int main()
{
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		u--;
		v--;
		a[u][v] = (a[u][v] + mod - w) % mod;
		a[v][v] = (a[v][v] + w) % mod;
		if (!t)
		{
			a[v][u] = (a[v][u] + mod - w) % mod;
			a[u][u] = (a[u][u] + w) % mod;
		}
	}
	printf("%d\n", work());
	return 0;
}