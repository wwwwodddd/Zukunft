#include <bits/stdc++.h>
using namespace std;
int n, a[1020];
long long z, x;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%lld", &x);
			if (i > j)
			{
				z += x * min(a[i], a[j]);			
			}
		}
	}
	printf("%lld\n", z);
	return 0;
}
