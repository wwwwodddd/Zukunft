#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int c[100020];
pair<int, int> a[100020];
multiset<int> s;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + m);
	for (int i = 1, j = 0; i <= n; i++)
	{
		for (;j < m && a[j].first <= i; j++)
		{
			s.insert(a[j].second);
		}
		while (s.size() > c[i])
		{
			s.erase(--s.end());
		}
		z += s.count(i);
		s.erase(i);
	}
	printf("%d\n", z);
	return 0;
}