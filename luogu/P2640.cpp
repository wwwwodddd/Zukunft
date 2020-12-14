#include <bits/stdc++.h>
using namespace std;
int n, k, c;
int v[10020];
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 2; i <= n; i++)
	{
		if (!v[i])
		{
			for (int j = i + i; j <= n; j += i)
			{
				v[j] = 1;
			}
		}
	}
	for (int i = 2; i + k <= n; i++)
	{
		if (!v[i] && !v[i + k])
		{
			printf("%d %d\n", i, i + k);
			c++;
		}
	}
	if (c == 0)
	{
		printf("empty\n");
	}
	return 0;
}