#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	int z = n;
	for (int i = 1; i <= n; i++)
	{
		int c = 0, x;
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &x);
			c += x;
		}
		z = min(z, c);
	}
	printf("%d\n", z * 2);
	return 0;
}