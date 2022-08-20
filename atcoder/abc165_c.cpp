#include <bits/stdc++.h>
using namespace std;
int n, m, q, z;
int a[60];
int b[60];
int c[60];
int d[60];
int e[20];
void dfs(int x)
{
	if (x == n + 1)
	{
		int s = 0;
		for (int i = 0; i < q; i++)
		{
			if (e[b[i]] - e[a[i]] == c[i])
			{
				s += d[i];
			}
		}
		z = max(z, s);
	}
	else
	{
		for (e[x] = e[x - 1]; e[x] <= m; e[x]++)
		{
			dfs(x + 1);
		}
	}
}
int main()
{
	cin >> n >> m >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	e[0] = 1;
	dfs(1);
	cout << z << endl;
	return 0;
}
