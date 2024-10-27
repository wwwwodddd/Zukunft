#include <bits/stdc++.h>
using namespace std;
int t, n;
pair<int, int> d[500020];
int a[500020];
int b[500020];
long long z;
void merge_sort(int l, int r)
{
	if (r - l <= 1)
	{
		return;
	}
	int m = (l + r) / 2;
	merge_sort(l, m);
	merge_sort(m, r);
	int i = l, j = m, k = l;
	while (i < m || j < r)
	{
		if (j == r || i < m && a[i] <= a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			z += m - i;
			b[k++] = a[j++];
		}
	}
	for (int i = l; i < r; i++)
	{
		a[i] = b[i];
	}
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &d[i].first, &d[i].second);
		}
		sort(d, d + n);
		for (int i = 0; i < n; i++)
		{
			a[i] = d[i].second;
		}
		z = 0;
		merge_sort(0, n);
		printf("%lld\n", z);
	}
	return 0;
}