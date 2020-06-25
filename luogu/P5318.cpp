#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[100020];
bool v[100020];
void dfs(int x)
{
	v[x] = 1;
	cout << x << " ";
	for (int i: a[x])
	{
		if (!v[i])
		{
			dfs(i);
		}
	}
}
void bfs(int x)
{
	memset(v, 0, sizeof v);
	queue<int> q;
	q.push(x);
	v[x] = 1;
	while (q.size())
	{
		int u = q.front();
		q.pop();
		cout << u << " ";
		for (int i: a[u])
		{
			if (!v[i])
			{
				q.push(i);
				v[i] = 1;
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(a[i].begin(), a[i].end());
	}
	dfs(1);
	cout << endl;
	bfs(1);
	cout << endl;
	return 0;
}