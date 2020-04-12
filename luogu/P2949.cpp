#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<int> > q;
pair<int, int> a[100020];
long long z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		z += a[i].second;
		q.push(a[i].second);
		if (q.size() > a[i].first)
		{
			z -= q.top();
			q.pop();
		}
	}
	printf("%lld\n", z);
	return 0;
}