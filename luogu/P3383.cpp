#include <bits/stdc++.h>
int n, q, k;
int v[100000020];
int p[6000020], pc;
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++)
	{
		if (!v[i])
		{
			p[pc++] = i;
		}
		for (int j = 0; j < pc && i * p[j] <= n; j++)
		{
			v[i * p[j]] = p[j];
			if (v[i] == p[j])
			{
				break;
			}
		}
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &k);
		printf("%d\n", p[k-1]);
	}
	return 0;
}