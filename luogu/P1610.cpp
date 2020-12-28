#include <bits/stdc++.h>
using namespace std;
int n, d, z;
int a[100000];
int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 1, l = a[0]; i + 1 < n; i++)
	{
		if (a[i + 1] - l <= d)
		{
			z++;
		}
		else
		{
			l = a[i];
		}
	}
	printf("%d\n", z);
	return 0;
}