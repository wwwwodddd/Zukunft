#include <bits/stdc++.h>
using namespace std;
int n, m, l, x, y;
vector<int> a[100020];
int d[2][100020];
queue<pair<int, int> > q;
int main()
{
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(d, 0x3f, sizeof d);
	for (int i: a[1])
	{
		d[1][i] = 1;
		q.push(make_pair(1, i));
	}
	while (q.size())
	{
		pair<int, int> u = q.front();
		q.pop();
		for (int i: a[u.second])
		{
			if (d[u.first ^ 1][i] == 0x3f3f3f3f)
			{
				d[u.first ^ 1][i] = d[u.first][u.second] + 1;
				q.push(make_pair(u.first ^ 1, i));
			}
		}
	}
	for (int i = 0; i < l; i++)
	{
		scanf("%d%d", &x, &y);
		puts(d[y & 1][x] > y ? "No" : "Yes");
	}
	return 0;
}