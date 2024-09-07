#include <bits/stdc++.h>
using namespace std;
int n, m, f;
int c[3];
int v[200020];
vector<int> a[200020];
void dfs(int x, int y)
{
	v[x] = y;
	c[y]++;
	for (int i : a[x])
	{
		if (v[i] == 0)
		{
			dfs(i, 3 - y);
		}
		else if (v[i] == y)
		{
			f = 1;
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	long long z = (long long)n * (n - 1) / 2 - m;
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == 0)
		{
			c[1] = c[2] = 0;
			dfs(i, 1);
			z -= (long long)(c[1] + c[2]) * (c[1] + c[2] - 1) / 2;
			z += (long long)c[1] * c[2];
			if (f)
			{
				z = 0;
				break;	
			}
		}
	}
	cout << z << endl;
	return 0;
}
