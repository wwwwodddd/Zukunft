#include <bits/stdc++.h>
using namespace std;
int n = 10000000;
int v[10000020];
int main()
{
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == 0)
		{
			for (int j = i; j <= n; j += i)
			{
				if (v[j] == 0)
				{
					v[j] = i;
				}
			}
		}
	}
	while (scanf("%d", &n) != EOF)
	{
		printf("1");
		while (n > 1)
		{
			printf(" x %d", v[n]);
			n /= v[n];
		}
		puts("");
	}
	return 0;
}