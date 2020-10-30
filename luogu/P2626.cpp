#include <bits/stdc++.h>
using namespace std;
unsigned n, f[50] = {0, 1}, v;
int main()
{
	scanf("%u", &n);
	for (unsigned i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	f[n] &= 0x7fffffff;
	printf("%u=", f[n]);
	for (unsigned i = 2, j = f[n]; i <= j; i++)
	{
		for (; j % i == 0; j /= i)
		{
			if (v)
			{
				printf("*");
			}
			printf("%d", i);
			v = 1;
		}
	}
	printf("\n");
	return 0;
}