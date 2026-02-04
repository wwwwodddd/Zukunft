#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[100020];
int s[100020];
int f[100020];
bool ok(long long lim)
{
	int j = 0;
	map<long long, long long> cur;
	cur[-1] = 0;
	cur[1e18] = 0;
	for (int i = 0; i < n; i++)
	{
		while (true)
		{
			if (j == m)
			{
				return false;
			}
			auto it = cur.upper_bound(s[i]);
			auto ti = it;
			ti--;
			if (ti->first + ti->second >= s[i])
			{
				ti->second += f[j] * a[i];
			}
			else
			{
				ti = cur.insert({s[i], f[j] * a[i]}).first;
			}
			while (true)
			{
				it = ti;
				it++;
				if (ti->first + ti->second >= it->first)
				{
					ti->second += it->second;
					cur.erase(it);
				}
				else
				{
					break;
				}
			}
			if (ti->first + ti->second > lim)
			{
				j++;
				cur.clear();
				cur[-1] = 0;
				cur[1e18] = 0;
			}
			else
			{
				break;
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &s[i]);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &f[i]);
		}
		long long L = 0, R = 1e18;
		while (L < R - 1)
		{
			long long M = (L + R) / 2;
			if (ok(M))
			{
				R = M;
			}
			else
			{
				L = M;
			}
		}
		printf("%lld\n", R);
	}
	return 0;
}