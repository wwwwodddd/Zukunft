#include <bits/stdc++.h>
using namespace std;
int n;
int c[22][22];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		c[i][0] = 1;
		printf("%d", c[i][0]);
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = c[i-1][j-1] + c[i-1][j];
			printf(" %d", c[i][j]);
		}
		puts("");
	}
	return 0;
}