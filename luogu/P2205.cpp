#include <bits/stdc++.h>
using namespace std;
int n, m, x, p, c, z;
char o;
pair<int, int> a[200020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %c", &x, &o);
		if (o == 'L')
		{
			a[i] = make_pair(p - x, +1);
			a[i + n] = make_pair(p, -1);
			p -= x;
		}
		else
		{
			a[i] = make_pair(p + x, -1);
			a[i + n] = make_pair(p, +1);
			p += x;
		}
	}
	sort(a, a + 2 * n);
	for (int i = 0; i + 1 < 2 * n; i++)
	{
		c += a[i].second;
		if (c >= m)
		{
			z += a[i + 1].first - a[i].first;
		}
	}
	printf("%d\n", z);
	return 0;
}