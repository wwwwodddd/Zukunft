#include <bits/stdc++.h>
using namespace std;
int n, q, o;
int c[26][100020];
char s[100020];
void change(int d, int x, int y)
{
	for (int i = x; i <= n; i += i & -i)
	{
		c[d][i] += y;
	}
}
int query(int d, int x)
{
	int re = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		re += c[d][i];
	}
	return re;
}
int main()
{
	scanf("%d%s%d", &n, s + 1, &q);
	for (int i = 1; i <= n; i++)
	{
		change(s[i] - 'a', i, 1);
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &o);
		if (o == 1)
		{
			int x;
			scanf("%d", &x);
			change(s[x] - 'a', x, -1);
			scanf(" %c", &s[x]);
			change(s[x] - 'a', x, +1);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			int b[26] = {};
			for (int j = 0; j < 26; j++)
			{
				b[j] = query(j, r) - query(j, l);
			}
			bool is_sorted = true;
			int st = l;
			for (int j = 0; j < 26; j++)
			{
				if (query(j, st + b[j]) - query(j, st) == b[j])
				{
					st += b[j];
				}
				else
				{
					is_sorted = false;
					break;
				}
			}
			if (!is_sorted)
			{
				printf("No\n");
				continue;
			}
			bool is_all = true;
			for (int j = s[l + 1] - 'a' + 1; j < s[r] - 'a'; j++)
			{
				if (b[j] != query(j, n))
				{
					is_all = false;
					break;
				}
			}
			if (!is_all)
			{
				printf("No\n");
				continue;
			}
			printf("Yes\n");
		}
	}
	return 0;
}