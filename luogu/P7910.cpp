#include <bits/stdc++.h>
using namespace std;
int n, q;
pair<int, int> b[8020];
int p[8020];
void gao()
{
	for (int i = 1; i <= n; i++)
	{
		p[b[i].second] = i;
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i].first);
		b[i].second = i;
	}
	sort(b + 1, b + 1 + n);
	gao();
	for (int i = 0; i < q; i++)
	{
		int o, x, y;
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d%d", &x, &y);
			b[p[x]].first = y;
			for (int i = 1; i < n; i++)
			{
				if (b[i] > b[i + 1])
				{
					swap(b[i], b[i + 1]);
				}
			}
			for (int i = n - 1; i > 0; i--)
			{
				if (b[i] > b[i + 1])
				{
					swap(b[i], b[i + 1]);
				}
			}
			gao();
		}
		else
		{
			scanf("%d", &x);
			printf("%d\n", p[x]);
		}
	}
	return 0;
}