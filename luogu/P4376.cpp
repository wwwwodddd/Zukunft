#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
vector<int> b[100020];
vector<int> z;
int n, m;
int in[100020];
priority_queue<int, vector<int>, greater<int> > q;
stack<int> s;
int size()
{
	return q.size() + s.size();
}
void push(int x, bool f)
{
	if (f)
	{
		s.push(x);
	}
	else
	{
		q.push(x);
	}
}
int top(bool f)
{
	int x;
	if (f)
	{
		x = s.top();
		s.pop();
	}
	else
	{
		x = q.top();
		q.pop();
	}
	return x;
}
int ok(int x, bool f)
{
	for (int i = 1; i <= n; i++)
	{
		a[i].clear();
		in[i] = 0;
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 1; j < b[i].size(); j++)
		{
			a[b[i][j - 1]].push_back(b[i][j]);
			in[b[i][j]]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0)
		{
			push(i, f);
		}
	}
	z.clear();
	while (size())
	{
		z.push_back(top(f));
		for (int i: a[z.back()])
		{
			if (!--in[i])
			{
				push(i, f);
			}
		}
	}
	return z.size() == n;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int l, x;
		scanf("%d", &l);
		for (int j = 0; j < l; j++)
		{
			scanf("%d", &x);
			b[i].push_back(x);
		}
	}
	int L = 0;
	int R = m + 1;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		(ok(M, 1) ? L : R) = M;
	}
	ok(L, 0);
	for (int i = 0; i < n; i++)
	{
		printf("%d%c", z[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}