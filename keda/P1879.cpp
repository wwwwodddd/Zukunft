#include <bits/stdc++.h>
using namespace std;
int n, x, mx, z;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		mx = max(mx, x);
		if (mx == i)
		{
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}