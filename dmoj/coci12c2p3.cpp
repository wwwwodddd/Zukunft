#include <bits/stdc++.h>
using namespace std;
int n, s, z;
int a[500020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	s = z = n - 1;
	for (int i = 0; i < n; i++)
	{
		if (s >= a[i] + 1)
		{
			s -= a[i] + 1;
			z--;
		}
	}
	printf("%d\n", z);
	return 0;
}
