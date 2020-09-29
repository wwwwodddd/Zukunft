#include <bits/stdc++.h>
using namespace std;
int n, m, x, c[1000];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		c[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < c[i]; j++)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}