#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
int n, m, u, v;
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
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &v, &u);
		u--;
		v--;
		a[u][v]--;
		a[v][v]++;
	}
	printf("%d\n", work());
	return 0;
}