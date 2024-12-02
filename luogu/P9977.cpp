#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long z;
pair<int, int> a[200020];
map<int, int> s;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	s[-k] = m;
	for (int i = 0; i < n; i++)
	{
		while (a[i].second > 0)
		{
			if (a[i].first - s.begin()->first >= k)
			{
				int c = min(a[i].second, s.begin()->second);
				a[i].second -= c;
				s.begin()->second -= c;
				z += c;
				if (s.begin()->second == 0)
				{
					s.erase(s.begin());
				}
				s[a[i].first] += c;
			}
			else
			{
				break;
			}
		}
	}
	printf("%lld\n", z);
	return 0;
}