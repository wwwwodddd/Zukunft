#include <bits/stdc++.h>
using namespace std;
int n, m, k, z;
int b[220];
pair<int, int> a[220];
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--)
	{
		if (b[a[i].second] > 0 && m > 0)
		{
			b[a[i].second]--;
			m--;
			z += a[i].first;
		}
	}
	printf("%d\n", z);
	return 0;
}