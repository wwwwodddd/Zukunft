#include <bits/stdc++.h>
using namespace std;
int t, na, nb, nc, pa, pb, pc;
int a[1020];
int b[1020];
int c[1020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%d", &na, &nb, &nc);
		for (int i = 0; i < na; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < nb; i++)
		{
			scanf("%d", &b[i]);
		}
		for (int i = 0; i < nc; i++)
		{
			scanf("%d", &c[i]);
		}
		sort(a, a + na);
		sort(b, b + nb);
		sort(c, c + nc);
		pa = pb = pc = 0;
		int z = max(a[pa], max(b[pb], c[pc])) - min(a[pa], min(b[pb], c[pc]));
		while (true)
		{
			if (a[pa] == min(a[pa], min(b[pb], c[pc])))
			{
				pa++;
			}
			else if (b[pb] == min(a[pa], min(b[pb], c[pc])))
			{
				pb++;
			}
			else
			{
				pc++;
			}
			if (pa == na || pb == nb || pc == nc)
			{
				break;
			}
			z = min(z, max(a[pa], max(b[pb], c[pc])) - min(a[pa], min(b[pb], c[pc])));
		}
		printf("%d\n", z * 2);
	}
	return 0;
}