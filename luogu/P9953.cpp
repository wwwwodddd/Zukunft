#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100020];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	int d = 1e9;
	for (int i = 1; i < n; i++)
	{
		if (a[i].second + a[i - 1].second == 1)
		{
			d = min(d, a[i].first - a[i - 1].first);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].second)
		{
			if (i == 0 || a[i - 1].second == 0 || a[i].first - a[i - 1].first >= d)
			{
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}