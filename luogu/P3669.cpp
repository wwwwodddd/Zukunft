#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100020];
int n, z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].second, &a[i].first);
	}
	sort(a, a + n);
	for (int i = 0, j = n - 1; i <= j;)
	{
		if (a[i].second > 0)
		{
			z = max(z, a[i].first + a[j].first);
		}
		if (a[i].second < a[j].second)
		{
			a[j].second -= a[i].second;
			i++;
		}
		else
		{
			a[i].second -= a[j].second;
			j--;
		}
	}
	printf("%d\n", z);
	return 0;
}