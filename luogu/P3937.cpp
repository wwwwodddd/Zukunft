#include <bits/stdc++.h>
using namespace std;
int n, t, k, z;
int a[3000020];
int main()
{
	scanf("%d%d%d", &n, &t, &k);
	k--;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= t; i++)
	{
		if ((t & i) == i)
		{
			z ^= a[(k + i) % n];
		}
	}
	printf("%d\n", z);
	return 0;
}