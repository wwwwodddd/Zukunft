#include <bits/stdc++.h>
using namespace std;
int t, n, m, l;
pair<int, int> a[200020];
pair<int, int> b[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%d", &n, &m, &l);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i].first, &a[i].second);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &b[i].first, &b[i].second);
		}
		priority_queue<int> q;
		int p = 1;
		int ans = 0;
		for (int i = 0, j = 0; i < n; i++)
		{
			while (j < m && b[j].first < a[i].first)
			{
				q.push(b[j++].second);
			}
			while (p < a[i].second - a[i].first + 2 && q.size())
			{
				p += q.top();
				q.pop();
				ans++;
			}
			if (p < a[i].second - a[i].first + 2)
			{
				ans = -1;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}