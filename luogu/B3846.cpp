#include <bits/stdc++.h>
using namespace std;
int x, y, z;
int main()
{
	scanf("%d%d", &x, &y);
	for (int i = x + 1; i < y; i++)
	{
		if (i % 400 == 0 || i % 100 != 0 && i % 4 == 0)
		{
			z += i;
		}
	}
	printf("%d\n", z);
	return 0;
}