#include <bits/stdc++.h>
using namespace std;
int n, m, l, b, f;
int q[200020];
char o, p;
int main()
{
	b = f = 100010;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %c %c", &o, &p);
		if (o == 'A')
		{
			if (p == 'L')
			{
				q[--b] = ++m;
			}
			else
			{
				q[f++] = ++m;
			}
		}
		else
		{
			scanf("%d", &l);
			if (p == 'L')
			{
				b += l;
			}
			else
			{
				f -= l;
			}
		}
	}
	for (int i = b; i < f; i++)
	{
		printf("%d\n", q[i]);
	}
	return 0;
}