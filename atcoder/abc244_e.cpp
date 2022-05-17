#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m, l, s, t, x, u, v;
vector<int> a[2020];
int f[2020][2020][2];
int main()
{
	cin >> n >> m >> l >> s >> t >> x;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	f[0][s][0] = 1;
	for (int i = 0; i < l; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int o = 0; o < 2; o++)
			{
				if (f[i][j][o] == 0)
				{
					continue;
				}
				for (int k : a[j])
				{
					int &g = f[i + 1][k][o ^ (k == x)];
					g = (g + f[i][j][o]) % p;
				}
			}
		}
	}
	cout << f[l][t][0] << endl;
	return 0;
}
