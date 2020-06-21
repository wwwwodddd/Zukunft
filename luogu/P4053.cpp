#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int n, s;
pair<int, int> a[150020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].second, &a[i].first);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		s += a[i].second;
		q.push(a[i].second);
		if (s > a[i].first)
		{
			s -= q.top();
			q.pop();
		}
	}
	printf("%d\n", int(q.size()));
	return 0;
}
