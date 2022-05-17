#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<int, int> a[400020];
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].first);
		a[i].second = -i;
	}
	sort(a, a + n);
	int p = -n, z = n;
	for (int i = 0; i < n; i++)
	{
		if (-a[i].second < k)
		{
			p = max(p, -a[i].second);
		}
		else
		{
			z = min(z, -a[i].second - p);
		}
	}
	if (z == n)
	{
		z = -1;
	}
	printf("%d\n", z);
	return 0;
}
