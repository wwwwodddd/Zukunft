#include <bits/stdc++.h>
using namespace std;
set<int> a;
set<pair<int, int> > b;
long long z;
void add(pair<int, int> u)
{
	set<pair<int, int> >::iterator it = b.lower_bound(u);
	while (it != b.end() && it->first <= u.second)
	{
		u.first = min(u.first, it->first);
		u.second = max(u.second, it->second);
		z -= it->second - it->first;
		it = b.erase(it);
	}
	if (it != b.begin())
	{
		it--;
		if (u.first <= it->second)
		{
			u.first = min(u.first, it->first);
			u.second = max(u.second, it->second);
			z -= it->second - it->first;
			b.erase(it);
		}
	}
	z += u.second - u.first;
	b.insert(u);
}
int main()
{
	int t, n, x;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		a.clear();
		b.clear();
		z = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			set<int>::iterator it = a.lower_bound(x);
			if (it != a.end())
			{
				add(make_pair(*it - x + 1, *it + x));
			}
			if (it != a.begin())
			{
				it--;
				add(make_pair(x - *it + 1, x + *it));
			}
			a.insert(x);
			if (i > 0)
			{
				printf("%lld ", z);
			}
		}
		printf("\n");
	}
	return 0;
}