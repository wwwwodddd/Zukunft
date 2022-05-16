#include <bits/stdc++.h>
using namespace std;
int t, n;
pair<int, int> a[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i].first);
			a[i].second = i + 1;
		}
		sort(a, a + n);
		if (n & 1)
		{
			printf("Case %d: %d\n", tt, a[n / 2].second);
		}
		else
		{
			printf("Case %d: %d\n", tt, min(a[n / 2].second, a[n / 2 - 1].second));
		}
	}
	return 0;
}