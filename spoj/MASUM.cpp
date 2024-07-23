#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	long long z = a[n - 1] - a[0];
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] > 0)
		{
			z += a[i];
		}
		else
		{
			z -= a[i];
		}
	}
	printf("%lld\n", z);
	return 0;
}