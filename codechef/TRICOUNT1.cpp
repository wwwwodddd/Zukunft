#include <bits/stdc++.h>
using namespace std;
int a[200020];
vector<pair<int, int> > b;
int main()
{
	int t, n;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		b.clear();
		for (int i = 1; i < n; i++)
		{
			b.push_back(make_pair(a[i] - a[i - 1] + 1, a[i] + a[i - 1]));
		}
		sort(b.begin(), b.end());
		long long s = 0, e = 0, z = 0;
		for (int i = 0; i < b.size(); i++)
		{
			if (e < b[i].first)
			{
				z += e - s;
				s = b[i].first;
				e = b[i].second;
			}
			else
			{
				e = max(e, (long long)b[i].second);
			}
		}
		z += e - s;
		printf("%lld\n", z);
	}
	return 0;
}