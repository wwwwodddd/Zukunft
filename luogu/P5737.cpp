#include <bits/stdc++.h>
using namespace std;
int x, y, z;
int main()
{
	scanf("%d%d", &x, &y);
	for (int i = x; i <= y; i++)
	{
		if (i % 400 == 0 || i % 100 != 0 && i % 4 == 0)
		{
			z++;
		}
	}
	printf("%d\n", z);
	for (int i = x; i <= y; i++)
	{
		if (i % 400 == 0 || i % 100 != 0 && i % 4 == 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}