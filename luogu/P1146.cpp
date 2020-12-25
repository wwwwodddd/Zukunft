#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", (i + (j > i)) % 2);
		}
		printf("\n");
	}
	return 0;
}