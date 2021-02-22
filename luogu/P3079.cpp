#include <bits/stdc++.h>
using namespace std;
int n, z;
pair<pair<int, int>, pair<int, int> > a[200020];
set<pair<int, int> > s;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int xa, ya, xb, yb;
		scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
		a[i + 0 * n] = make_pair(make_pair(xa, -1), make_pair(ya, -1));
		a[i + 1 * n] = make_pair(make_pair(xa, -1), make_pair(yb, +1));
		a[i + 2 * n] = make_pair(make_pair(xb, +1), make_pair(ya, -1));
		a[i + 3 * n] = make_pair(make_pair(xb, +1), make_pair(yb, +1));
	}
	sort(a, a + 4 * n);
	s.insert(make_pair(1000000000, -1));
	for (int i = 0; i < 4 * n; i++)
	{
		if (a[i].first.second < 0)
		{
			if (s.lower_bound(a[i].second)->second < 0)
			{
				if (a[i].second.second > 0)
				{
					z++;
				}
				s.insert(a[i].second);
			}
		}
		else
		{
			s.erase(a[i].second);
		}
	}
	printf("%d\n", z);
	return 0;
}