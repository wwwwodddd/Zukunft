#include <bits/stdc++.h>
int n, k;
int v[100000020];
int p[6000020], pc;
int main()
{
	scanf("%d", &n);
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
	printf("%d\n", pc);
	for (int i = 0; i < pc; i++)
	{
		printf("%d ", p[i]);
	}
	return 0;
}