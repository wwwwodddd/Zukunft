#include <bits/stdc++.h>
using namespace std;
pair<int, int> e[600020];
int n, m, c, r;
long long z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &e[i].first);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &e[i + n].first);
		e[i + n].second = 1;
	}
	sort(e, e + n + m);
	for (int i = 0; i < n + m; i++)
	{
		if (e[i].second)
		{
			if (!c || !r)
			{
				z += (long long)(n - 1) * e[i].first;
			}
			else
			{
				z += (long long)(n - c) * e[i].first;
			}
			r++;
		}
		else
		{
			if (!c || !r)
			{
				z += (long long)(m - 1) * e[i].first;
			}
			else
			{
				z += (long long)(m - r) * e[i].first;
			}
			c++;
		}
	}
	printf("%lld\n", z);
	return 0;
}