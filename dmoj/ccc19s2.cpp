#include <bits/stdc++.h>
using namespace std;
int t, n = 2000000;
int v[2000020];
int p[2000020], pc;
int main()
{
	v[0] = v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == 0)
		{
			p[pc++] = i;
			for (int j = i + i; j <= n; j += i)
			{
				v[j] = 1;
			}
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < pc; i++)
		{
			if (v[2 * n - p[i]] == 0)
			{
				printf("%d %d\n", p[i], 2 * n - p[i]);
				break;
			}
		}
	}
	return 0;
}