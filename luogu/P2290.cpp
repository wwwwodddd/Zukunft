#include <bits/stdc++.h>
using namespace std;
unsigned long long z = 1;
int n, x, s;
int main()
{
	scanf("%d", &n);
	for (int i = 0, k = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (n > 1 && x == 0)
		{
			z = 0;
		}
		s += x;
		for (int j = 1; j < x; j++)
		{
			z = z * ++k / j;
		}
	}
	if (s != n * 2 - 2)
	{
		z = 0;
	}
	printf("%llu\n", z);
	return 0;
}