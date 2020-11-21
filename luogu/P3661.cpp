#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int n, m, x, z;
pair<int, int> a[20020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		s.insert(x);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a[i].second, &a[i].first);
	}
	sort(a, a + m);
	for (int i = 0; i < m; i++)
	{
		multiset<int>::iterator it = s.lower_bound(a[i].second);
		if (it != s.end() && *it <= a[i].first)
		{
			s.erase(it);
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}