#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int j = 0, z = 0;
		for (int i = 0; i < n; i++)
		{
			if (j < i && a[i] - a[i - 1] > 1)
			{
				j = i;
			}
			while (a[j] <= a[i] - m)
			{
				j++;
			}
			z = max(z, i - j + 1);
		}
		printf("%d\n", z);
	}
	return 0;
}