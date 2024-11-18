#include <bits/stdc++.h>
using namespace std;
int t, n, p;
char a[100020];
char b[100020];
pair<int, int> z[400020];
void gao()
{
	int c = 0;
	int d = 0;
	int ans = 0;
	int zc = 0;
	for (int i = 1; i < n; i++)
	{
		c += (a[i] != a[i - 1]);
	}
	for (int i = 1; i < n; i++)
	{
		d += (b[i] != b[i - 1]);
	}
	if (a[n - 1] == b[n - 1])
	{
		ans++;
		char an = a[n - 1];
		char bn = b[n - 1];
		if (c == 0)
		{
			z[zc++] = (make_pair(2, 1));
			b[n - 1] = '1' + '2' - bn;
			d--;
		}
		else if (d == 0)
		{
			z[zc++] = (make_pair(1, 2));
			a[n - 1] = '1' + '2' - an;
			c--;
		}
		else if (b[0] == bn)
		{
			z[zc++] = (make_pair(2, 1));
			b[n - 1] = '1' + '2' - bn;
			d--;
		}
		else
		{
			z[zc++] = (make_pair(1, 2));
			a[n - 1] = '1' + '2' - an;
			c--;
		}
	}

	{
		if (a[0] == b[n - 1] && a[n - 1] == b[0])
		{
			assert(c % 2 == 1 && d % 2 == 1);
			ans += c + d + 1;
			for (int i = 0; i < d; i++)
			{
				if (i % 2 == 0)
				{
					z[zc++] = (make_pair(2, 3));
				}
				else
				{
					z[zc++] = (make_pair(2, 1));
				}
			}
			for (int i = 0; i < c; i++)
			{
				if (i % 2 == 0)
				{
					z[zc++] = (make_pair(1, 2));
				}
				else
				{
					z[zc++] = (make_pair(1, 3));
				}
			}
			z[zc++] = (make_pair(3, 1));
		}
		else if (a[0] == a[n - 1] && a[0] == b[0])
		{
			ans += c + d + 2;
			for (int i = 0; i <= c; i++)
			{
				if (i % 2 == 0)
				{
					z[zc++] = (make_pair(1, 3));
				}
				else
				{
					z[zc++] = (make_pair(1, 2));
				}
			}
			for (int i = 0; i < d; i++)
			{
				if (i % 2 == 0)
				{
					z[zc++] = (make_pair(2, 1));
				}
				else
				{
					z[zc++] = (make_pair(2, 3));
				}
			}
			z[zc++] = (make_pair(3, 2));
		}
		else if (b[0] == b[n - 1] && a[0] == b[0])
		{
			ans += c + d + 2;
			for (int i = 0; i <= d; i++)
			{
				if (i % 2 == 0)
				{
					z[zc++] = (make_pair(2, 3));
				}
				else
				{
					z[zc++] = (make_pair(2, 1));
				}
			}
			for (int i = 0; i < c; i++)
			{
				if (i % 2 == 0)
				{
					z[zc++] = (make_pair(1, 2));
				}
				else
				{
					z[zc++] = (make_pair(1, 3));
				}
			}
			z[zc++] = (make_pair(3, 1));
		}
		else if (a[0] == a[n - 1] && b[n - 1] == b[0])
		{
			if (c == 0 && d == 0)
			{
			}
			else if (d == 0)
			{
				ans += c + 1;
				for (int i = 0; i < c; i++)
				{
					if (i % 2 == 0)
					{
						z[zc++] = (make_pair(1, 3));
					}
					else
					{
						z[zc++] = (make_pair(1, 2));
					}
				}
				z[zc++] = (make_pair(3, 1));
			}
			else if (c == 0)
			{
				ans += d + 1;
				for (int i = 0; i < d; i++)
				{
					if (i % 2 == 0)
					{
						z[zc++] = (make_pair(2, 3));
					}
					else
					{
						z[zc++] = (make_pair(2, 1));
					}
				}
				z[zc++] = (make_pair(3, 2));
			}
			else
			{
				ans += c + d + 1;
				z[zc++] = (make_pair(2, 3));
				for (int i = 0; i < c; i++)
				{
					if (i % 2 == 0)
					{
						z[zc++] = (make_pair(1, 2));
					}
					else
					{
						z[zc++] = (make_pair(1, 3));
					}
				}
				z[zc++] = (make_pair(2, 1));
				for (int i = 0; i < d - 2; i++)
				{
					if (i % 2 == 0)
					{
						z[zc++] = (make_pair(2, 3));
					}
					else
					{
						z[zc++] = (make_pair(2, 1));
					}
				}
				z[zc++] = (make_pair(3, 2));
			}
		}
		else
		{
			assert(false);
		}
	}
	printf("%d\n", ans);
	if (p > 1)
	{
		assert(zc == ans);
		for (int i = 0; i < zc; i++)
		{
			printf("%d %d\n", z[i].first, z[i].second);
		}
	}
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%s%s", &n, &p, a, b);
		gao();
	}
	return 0;
}