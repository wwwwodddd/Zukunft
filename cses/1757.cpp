#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[200020];
int d[200020];
priority_queue<int> q;
deque<int> z;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[y].push_back(x);
		d[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size() > 0)
	{
		int x = q.top();
		z.push_front(x);
		q.pop();
		for (int i: a[x])
		{
			if (--d[i] == 0)
			{
				q.push(i);
			}
		}
	}
	for (int i: z)
	{
		cout << i << " ";
	}
	return 0;
}