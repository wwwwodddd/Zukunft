#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<int> a[1000020];
int f[1000020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}
		for (int i = 2; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			a[x].push_back(i);
		}
		for (int i = n; i > 0; i--)
		{
			priority_queue<int, vector<int>, greater<int>> q;
			for (int j : a[i])
			{
				q.push(f[j]);
			}
			if (q.size() == 0)
			{
				f[i] = 0;
			}
			else if (q.size() == 1)
			{
				f[i] = q.top() + 1;
			}
			else
			{
				while (q.size() > 1)
				{
					q.pop();
					q.push(q.top() + 1);
					q.pop();
				}
				f[i] = q.top();
			}
		}
		printf("%d\n", f[1]);
	}
	return 0;
}