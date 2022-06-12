#include <bits/stdc++.h>
using namespace std;
int t, b, w;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &b, &w);
		if ((b == 0 || w == 0) && b + w > 1)
		{
			printf("-1\n");
			continue;
		}
		if (b < w)
		{
			for (int i = 0; i < b; i++)
			{
				printf("B");
			}
			for (int i = 0; i < w; i++)
			{
				printf("W");
			}
		}
		else
		{
			for (int i = 0; i < w; i++)
			{
				printf("W");
			}
			for (int i = 0; i < b; i++)
			{
				printf("B");
			}
		}
		printf("\n");
		for (int i = 2; i <= b + w; i++)
		{
			printf("%d %d\n", 1, i);
		}
	}
	return 0;
}