#include <bits/stdc++.h>
using namespace std;
int n, x, y;
vector<int> a[1000020];
int c[1000020];
int dfs(int x, int y)
{
	int s = 1;
	for (int i: a[x])
	{
		if (i != y)
		{
			s += dfs(i, x);
		}
	}
	c[s]++;
	return s;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = n - 1; i > 1; i--)
	{
		if (n % i == 0)
		{
			int s = 0;
			for (int j = i; j <= n; j += i)
			{
				s += c[j];
			}
			if (s == n / i)
			{
				printf("%d ", s - 1);
			}
		}
	}
	printf("%d\n", n - 1);
	return 0;
}