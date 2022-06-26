#include <bits/stdc++.h>
using namespace std;
int t, n, m;
vector<int> a[200020];
void huan(int x, int y)
{
	for (int i = 0; i < n; i++)
	{
		swap(a[i][x], a[i][y]);
	}
}
bool pan()
{
	for (int i = 0; i < n; i++)
	{
		if (!is_sorted(a[i].begin(), a[i].end()))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			a[i].resize(m);
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		int x = -1, y = -1;
		for (int i = 0; i < n; i++)
		{
			if (!is_sorted(a[i].begin(), a[i].end()))
			{
				int p = -1, q = -1;
				for (int j = 1; j < a[i].size(); j++)
				{
					if (a[i][j - 1] > a[i][j])
					{
						p = j - 1;
						q = j;
						break;
					}
				}
				int u = upper_bound(a[i].begin(), a[i].begin() + q, a[i][q]) - a[i].begin();
				huan(u, q);
				if (pan())
				{
					x = u;
					y = q;
					huan(u, q);
					break;
				}
				huan(u, q);
				
				int v = -1;
				for (int j = q; j < a[i].size(); j++)
				{
					if (a[i][j] <= a[i][q] && (j + 1 == a[i].size() || a[i][j + 1] > a[i][q]))
					{
						v = j;
						break;
					}
				}
				if (v != -1)
				{
					huan(p, v);
					if (pan())
					{
						x = p;
						y = v;
						huan(p, v);
						break;
					}
					huan(p, v);
				}
			}
		}
		if (pan())
		{
			puts("1 1");
		}
		else if (x == -1)
		{
			puts("-1");
		}
		else
		{
			printf("%d %d\n", x + 1, y + 1);
		}
	}
	return 0;
}