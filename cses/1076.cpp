#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200020];
int main()
{
	multiset<int> low, high;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < k; i++)
	{
		low.insert(a[i]);
	}
	// low.size() == (k + 1) / 2
	// high.size() == k / 2
	for (int i = 0; i < k / 2; i++)
	{
		high.insert(*--low.end());
		low.erase(--low.end());
	}
	printf("%d ", *--low.end());
	for (int i = k; i < n; i++)
	{
		// insert a[i];
		if (a[i] <= *--low.end())
		{
			low.insert(a[i]);
		}
		else
		{
			high.insert(a[i]);
		}
		// delete a[i-k];
		if (high.find(a[i - k]) != high.end())
		{
			high.erase(high.find(a[i - k]));
		}
		else
		{
			low.erase(low.find(a[i - k]));
		}
		while (high.size() > low.size())
		{
			low.insert(*high.begin());
			high.erase(high.begin());
		}
		while (high.size() + 1 < low.size())
		{
			high.insert(*--low.end());
			low.erase(--low.end());
		}
		assert(high.size() == low.size() || high.size() + 1 == low.size());
		printf("%d ", *--low.end());
	}
	return 0;
}