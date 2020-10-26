#include <bits/stdc++.h>
using namespace std;
int n, g, b, d;
long long z;
pair<int, int> a[50020];
deque<pair<int, int> > q;
int main()
{
	scanf("%d%d%d%d", &n, &g, &b, &d);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a + 1, a + n + 1);
	a[n + 1].first = d;
	q.push_back(make_pair(b, 0));
	for (int i = 1; i <= n + 1; i++)
	{
		int l = a[i].first - a[i - 1].first;
		while (l > 0 && q.size() > 0)
		{
			if (q.front().first > l)
			{
				z += (long long)l * q.front().second;
				b -= l;
				q.front().first -= l;
				l = 0;
			}
			else
			{
				z += (long long)q.front().first * q.front().second;
				b -= q.front().first;
				l -= q.front().first;
				q.pop_front();
			}
		}
		if (l > 0)
		{
			printf("-1\n");
			return 0;
		}
		while (q.size() > 0 && a[i].second <= q.back().second)
		{
			b -= q.back().first;
			q.pop_back();
		}
		q.push_back(make_pair(g - b, a[i].second));
		b = g;
	}
	printf("%lld\n", z);
	return 0;
}