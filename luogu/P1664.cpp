#include <bits/stdc++.h>
using namespace std;
int n, x, m, d, z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x)
		{
			if (m > 0)
			{
				d = max(0, d - (1 << (m - 1)));
			}
			m = 0;
			d++;
			z += 1 + (d >= 3) + (d >= 7) + (d >= 30) + (d >= 120) + (d >= 365);
		}
		else
		{
			m++;
		}
	}
	printf("%d\n", z);
	return 0;
}