#include <bits/stdc++.h>
using namespace std;
int t, n, m, k;
int h[100020];
int x[100020];
bool ok(int times)
{
	vector<pair<int, int> > a;
	for (int i = 1; i <= n; i++)
	{
		if ((long long)times * m >= h[i])
		{
			int d = m - (h[i] + times - 1) / times;
			a.emplace_back(x[i] - d, +1);
			a.emplace_back(x[i] + d + 1, -1);
		}
	}
	sort(a.begin(), a.end());
	int s = 0;
	for (const auto &i : a)
	{
		s += i.second;
		if (s >= k)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &h[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x[i]);
		}
		int L = 0;
		int R = 1e9 + 1;
		while (L < R - 1)
		{
			int M = (L + R) / 2;
			if (ok(M))
			{
				R = M;
			}
			else
			{
				L = M;
			}
		}
		if (R > 1e9)
		{
			R = -1;
		}
		printf("%d\n", R);
	}
	return 0;
}