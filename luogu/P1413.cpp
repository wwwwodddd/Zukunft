#include <bits/stdc++.h>
using namespace std;
int n, x, y, l, z;
int a[1020];
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[i] = 200000 * x + y;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (l + 60 <= a[i])
		{
			l = a[i];
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}