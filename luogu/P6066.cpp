#include <bits/stdc++.h>
using namespace std;
vector<int> a[10020];
int n, m, x, y;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	stack<int> s;
	s.push(1);
	while (s.size() > 0)
	{
		int u = s.top();
		if (a[u].size() > 0)
		{
			s.push(a[u].back());
			a[u].pop_back();
		}
		else
		{
			printf("%d\n", u);
			s.pop();
		}
	}
	return 0;
}