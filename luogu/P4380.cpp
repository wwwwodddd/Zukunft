#include <bits/stdc++.h>
using namespace std;
int n, ans1, ans2;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int s[252][252];
int r[252][252], rc;
int c[65220];
int d[65220];
int v[65220], vc;
vector<int> a[65220];
vector<int> b[1000020];
pair<int, int> u;
bool in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}
int search(int x, int y)
{
	r[x][y] = rc;
	int re = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in(nx, ny) && !r[nx][ny] && s[nx][ny] == s[x][y])
		{
			re += search(nx, ny);
		}
	}
	return re;
}
int dfs(int x)
{
	v[x] = vc;
	int re = c[x];
	for (int i: a[x])
	{
		if (v[i] != vc && (d[i] == u.first || d[i] == u.second))
		{
			re += dfs(i);
		}
	}
	return re;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &s[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!r[i][j])
			{
				rc++;
				c[rc] = search(i, j);
				d[rc] = s[i][j];
				b[s[i][j]].push_back(rc);
				ans1 = max(ans1, c[rc]);
			}
		}
	}
	set<pair<int, int> > t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + 1 < n && s[i][j] != s[i + 1][j])
			{
				a[r[i][j]].push_back(r[i + 1][j]);
				a[r[i + 1][j]].push_back(r[i][j]);
				int x = min(s[i][j], s[i + 1][j]);
				int y = max(s[i][j], s[i + 1][j]);
				t.insert(make_pair(x, y));
			}
			if (j + 1 < n && s[i][j] != s[i][j + 1])
			{
				a[r[i][j]].push_back(r[i][j + 1]);
				a[r[i][j + 1]].push_back(r[i][j]);
				int x = min(s[i][j], s[i][j + 1]);
				int y = max(s[i][j], s[i][j + 1]);
				t.insert(make_pair(x, y));
			}
		}
	}
	for (pair<int, int> i: t)
	{
		u = i;
		vc++;
		for (int j: b[u.first])
		{
			if (v[j] != vc)
			{
				ans2 = max(ans2, dfs(j));
			}
		}
		for (int j: b[u.second])
		{
			if (v[j] != vc)
			{
				ans2 = max(ans2, dfs(j));
			}
		}
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}