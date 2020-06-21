#include <bits/stdc++.h>
using namespace std;
int n, p;
pair<int, int> a[100020];
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return (long long)a.second * b.first < (long long)b.second * a.first;
}
void work()
{
	long long sa = 0, sb = 0;
	for (int i = 1; i <= n; i++)
	{
		sa += a[i-1].first;
		sb += a[i-1].second;
		if (sa > p && sb * a[i].first <= a[i].second * (sa - p))
		{
			printf("%.6f\n", (double)sb / (sa - p));
			return;
		}
	}
	printf("-1\n");
}
int main()
{
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n, cmp);
	work();
	return 0;
}