#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans;
int f[100020];
long long s[100020];
long long l[100020];
priority_queue<int> q[100020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%lld%lld", &f[i], &s[i], &l[i]);
		q[i].push(s[i]);
	}
	for (int i = n; i > 0; i--)
	{
		while (s[i] > m)
		{
			s[i] -= q[i].top();
			q[i].pop();
		}
		ans = max(ans, (long long)q[i].size() * l[i]);
		s[f[i]] += s[i];
		if (q[f[i]].size() < q[i].size())
		{
			q[f[i]].swap(q[i]);
		}
		while (q[i].size())
		{
			q[f[i]].push(q[i].top());
			q[i].pop();
		}
	}
	printf("%lld\n", ans);
	return 0;
}