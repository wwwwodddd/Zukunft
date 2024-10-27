#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200020];
int main()
{
	multiset<int> low, high;
	long long ls = 0, hs = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < k; i++)
	{
		low.insert(a[i]);
		ls += a[i];
	}
	// low.size() == (k + 1) / 2
	// high.size() == k / 2
	for (int i = 0; i < k / 2; i++)
	{
		int u = *--low.end();
		high.insert(u);
		hs += u;
		low.erase(low.find(u));
		ls -= u;
	}
	long long median = *--low.end();
	printf("%lld ", hs - high.size() * median + low.size() * median - ls);
	for (int i = k; i < n; i++)
	{
		// insert a[i];
		if (a[i] <= *--low.end())
		{
			low.insert(a[i]);
			ls += a[i];
		}
		else
		{
			high.insert(a[i]);
			hs += a[i];
		}
		// delete a[i-k];
		if (high.find(a[i - k]) != high.end())
		{
			high.erase(high.find(a[i - k]));
			hs -= a[i - k];
		}
		else
		{
			low.erase(low.find(a[i - k]));
			ls -= a[i - k];
		}
		while (high.size() > low.size())
		{
			int u = *high.begin();
			low.insert(u);
			ls += u;
			high.erase(high.find(u));
			hs -= u;
		}
		while (high.size() + 1 < low.size())
		{
			int u = *--low.end();
			high.insert(u);
			hs += u;
			low.erase(low.find(u));
			ls -= u;
		}
		long long median = *--low.end();
		printf("%lld ", hs - high.size() * median + low.size() * median - ls);
	}
	return 0;
}