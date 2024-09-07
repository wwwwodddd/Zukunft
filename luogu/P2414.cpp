#include <bits/stdc++.h>
using namespace std;
const int M = 100020;
vector<int> e[M];
int t[M][26], f[M], c[M], a[M][2], h[M], d[M], l[M], r[M], z[M], p[M];
int n, m, tt, tim;
char o[M];
void bfs()
{
	queue<int> q;
	q.push(0);
	f[0] = 0;
	while (q.size())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < 26; i++)
		{
			if (int &y = t[x][i])
			{
				f[y] = x ? t[f[x]][i] : 0;
				e[f[y]].push_back(y);
				q.push(y);
			}
			else
			{
				y = t[f[x]][i];
			}
		}
	}
}
void dfs(int x)
{
	l[x] = tim;
	for (int i : e[x])
	{
		dfs(i);
	}
	r[x] = ++tim;
}
int G(int x)
{
	int re = 0;
	for (; x; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
void R(int x, int y)
{
	for (; x <= tim; x += x & -x)
	{
		c[x] += y;
	}
}
int main()
{
	scanf("%s", o);
	n = strlen(o);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[i][1] = x;
		a[i][0] = h[y];
		h[y] = i;
	}
	stack<int> s;
	s.push(0);
	tt = 1;
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (o[i] == 'P')
		{
			p[++k] = s.top();
		}
		else if (o[i] == 'B')
		{
			d[i] = s.top();
			s.pop();
			j = s.top();
		}
		else
		{
			if (!t[j][o[i] - 'a'])
			{
				t[j][o[i] - 'a'] = tt++;
			}
			j = t[j][o[i] - 'a'];
			d[i] = j;
			s.push(j);
		}
	}
	bfs();
	dfs(0);
	for (int i = 0, k = 0; i < n; i++)
	{
		if (o[i] == 'P')
		{
			for (int j = h[++k]; j; j = a[j][0])
			{
				z[j] = G(r[p[a[j][1]]]) - G(l[p[a[j][1]]]);
			}
		}
		else if (o[i] == 'B')
		{
			R(r[d[i]], -1);
		}
		else
		{
			R(r[d[i]], 1);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}