#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100020];
int n;
long long s, z;
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.first < a.second)
	{
		if (b.first < b.second)
		{
			return a.first < b.first;
		}
		else
		{
			return true;
		}
	}
	else
	{
		if (b.first < b.second)
		{
			return false;
		}
		else
		{
			return b.second < a.second;
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
	{
		s += a[i].first;
		z = max(z, s) + a[i].second;
	}
	printf("%lld\n", z);
	return 0;
}