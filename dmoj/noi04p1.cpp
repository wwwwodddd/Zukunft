#include <bits/stdc++.h>
const int inf = 100000;
int c[300005];
int dd;
int G(int x)
{
	int re = 0;
	for (; x; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
void R(int x, int y)
{
	for (; x <= 300000; x += x & -x)
	{
		c[x] += y;
	}
}
int A(int x)
{
	int re = 0, cnt = 0;
	for (int i = 19; i >= 0; i--)
	{
		re += (1 << i);
		if (re > 300000 || cnt + c[re] >= x)
		{
			re -= (1 << i);
		}
		else
		{
			cnt += c[re];
		}
	}
	return re + 1;
}
char o[5];
int tot, del, x;
int main()
{
	int m, z;
	while (~scanf("%d%d", &m, &z))
	{
		memset(c, 0, sizeof(c));
		dd = tot = del = 0;
		while (m--)
		{
			scanf("%s%d", o, &x);
			if (o[0] == 'I')
			{
				if (x < z)
				{
					continue;
				}
				R(x - dd + inf, 1);
				tot++;
			}
			else if (o[0] == 'S')
			{
				dd -= x;
				int tmp = G(z - 1 - dd + inf);
				tot -= tmp;
				del += tmp;
				for (int i = 1; i <= z - 1 - dd + inf; i++)
				{
					if (c[i])
					{
						R(i, -c[i]);
					}
				}
			}
			else if (o[0] == 'A')
			{
				dd += x;
			}
			else
			{
				if (x > tot)
				{
					puts("-1");
				}
				else
				{
					printf("%d\n", A(tot - x + 1) + dd - inf);
				}
			}
		}
		printf("%d\n", del);
	}
	return 0;
}