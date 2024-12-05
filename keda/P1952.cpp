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
			printf("%c", i >> j & 1 ? 'Y' : 'N');
		}
		printf("\n");
	}
	return 0;
}