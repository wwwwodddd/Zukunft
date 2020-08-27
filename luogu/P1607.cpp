#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, pair<int, int> > a[50020];
int main()
{
	scanf("%d%*d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a[i].first, &a[i].second.first, &a[i].second.second);
	}
	sort(a, a + n);
	multiset<int> s;
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		while (s.size() && *s.begin() <= a[i].first)
		{
			s.erase(s.begin());
		}
		for (int j = 0; j < a[i].second.second; j++)
		{
			if (s.size() < m)
			{
				s.insert(a[i].second.first);
				z++;
			}
			else if (a[i].second.first < *--s.end())
			{
				s.erase(--s.end());
				s.insert(a[i].second.first);
			}
			else
			{
				break;
			}
		}
	}
	printf("%d\n", z);
	return 0;
}