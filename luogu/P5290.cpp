#include <bits/stdc++.h>
using namespace std;
int n;
int m[200020];
vector<int> a[200020];
priority_queue<int> q[200020];
void merge(priority_queue<int> &q, priority_queue<int> &p)
{
	vector<int> o;
	if (q.size() < p.size())
	{
		q.swap(p);
	}
	while (p.size())
	{
		o.push_back(max(q.top(), p.top()));
		q.pop();
		p.pop();
	}
	for (int i: o)
	{
		q.push(i);
	}
}
void dfs(int x)
{
	for (int i: a[x])
	{
		dfs(i);
		merge(q[x], q[i]);
	}
	q[x].push(m[x]);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &m[i]);
	}
	for (int i = 2; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x].push_back(i);
	}
	dfs(1);
	long long z = 0;
	while (q[1].size())
	{
		z += q[1].top();
		q[1].pop();
	}
	printf("%lld\n", z);
	return 0;
}