#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0, k = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%02d", ++k);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 1, k = 0; i <= n; i++)
	{
		for (int j = i; j < n; j++)
		{
			printf("  ");
		}
		for (int j = 0; j < i; j++)
		{
			printf("%02d", ++k);
		}
		printf("\n");
	}
	return 0;
}