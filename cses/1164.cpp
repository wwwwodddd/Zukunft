#include <bits/stdc++.h>
using namespace std;
int n;
pair<pair<int, int>, int> a[200020];
multiset<pair<int, int> > s;
int z[200020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first.first, &a[i].first.second);
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (s.size() > 0 && s.begin()->first < a[i].first.first)
		{
			z[a[i].second] = s.begin()->second;
			s.erase(s.begin());
		}
		else
		{
			z[a[i].second] = s.size() + 1;
		}
		s.insert(make_pair(a[i].first.second, z[a[i].second]));
	}
	printf("%lu\n", s.size());
	for (int i = 0; i < n; i++)
	{
		printf("%d ", z[i]);
	}
	return 0;
}