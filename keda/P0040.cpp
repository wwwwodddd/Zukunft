#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (i >> j & 1)
			{
				printf("%d ", n - 1 - j);
			}
		}
		printf("\n");
	}
	return 0;
}