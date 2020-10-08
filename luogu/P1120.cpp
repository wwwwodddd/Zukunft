#include <bits/stdc++.h>
using namespace std;
int n, x, s, c[51], mx, l;
void dfs(int d, int x, int y)
{
	if (d == 0)
	{
		printf("%d\n", l);
		exit(0);
	}
	else if (x == 0)
	{
		dfs(d - 1, l, mx);
	}
	else
	{
		for (int i = min(x, y); i > 0; i--)
		{
			if (c[i])
			{
				c[i]--;
				dfs(d, x - i, i);
				c[i]++;
				if (x == l || x == i)
				{
					break;
				}
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x <= 50)
		{
			s += x;
			c[x]++;
			mx = max(mx, x);
		}
	}
	for (l = mx; l <= s; l++)
	{
		if (s % l == 0)
		{
			dfs(s / l, l, mx);
		}
	}
	return 0;
}