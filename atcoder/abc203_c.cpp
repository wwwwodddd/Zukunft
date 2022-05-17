#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
pair<long long, int> a[200020];
int main()
{
	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (a[i].first <= m)
		{
			m += a[i].second;
		}
	}
	printf("%lld\n", m);
	return 0;
}
