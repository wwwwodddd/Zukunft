#include <bits/stdc++.h>
using namespace std;
int p[120], sp;
int q[1200000], bb, ff;
int ans, n, m, s, t, tot;
int h[100020];
int d[100020];
int r[100020];
int v[100020];
int pp[100020];
int a[4000020][4];
int c[120][120];
int us[10020];
int tp[10020];
int cho;
int vv;
void add(int x, int y, int z, int w)
{
	tot++;
	a[tot][0] = h[x];
	a[tot][1] = y;
	a[tot][2] = z;
	a[tot][3] = w;
	h[x] = tot;

	tot++;
	a[tot][0] = h[y];
	a[tot][1] = x;
	a[tot][2] = 0;
	a[tot][3] = -w;
	h[y] = tot;
}
int spfa()
{
	memset(d, 0x3f, sizeof d);
	d[s] = 0;
	deque<int> q;
	q.push_back(s);
	while (q.size())
	{
		int u = q.front();
		q.pop_front();
		v[u] = 0;
		for (int i = h[u]; i; i = a[i][0])
			if (a[i][2] && d[a[i][1]] > d[u] + a[i][3])
			{
				d[a[i][1]] = d[u] + a[i][3];
				r[a[i][1]] = i;
				pp[a[i][1]] = u;
				if (!v[a[i][1]])
				{
					if (bb < ff && d[a[i][1]] < d[q[bb]])
					{
						q.push_front(a[i][1]);
					}
					else
					{
						q.push_back(a[i][1]);
					}
					v[a[i][1]] = 1;
				}
			}
	}
	return d[t] != 0x3f3f3f3f;
}
void ek()
{
	int u = t;
	cho = tp[pp[t]];
	while (u != s)
	{
		a[r[u]][2]--;
		a[r[u] ^ 1][2]++;
		ans += a[r[u]][3];
		u = pp[u];
	}
}
int main()
{
	tot = 1;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", p + i);
		sp += p[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", c[i] + j);
		}
	}
	s = m + n;
	t = s + 1;
	vv = t + 1;
	for (int i = 0; i < n; i++)
	{
		add(s, m + i, p[i], 0);
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			add(m + i, k, 1, c[i][k]);
		}
	}
	for (int k = 0; k < m; k++)
	{
		add(k, t, 1, 0);
		tp[k] = k;
		us[k] = 1;
	}
	while (spfa())
	{
		ek();
		us[cho]++;
		for (int i = 0; i < n; i++)
		{
			add(m + i, vv, 1, c[i][cho] * us[cho]);
		}
		add(vv, t, 1, 0);
		tp[vv] = cho;
		vv++;
	}
	printf("%d\n", ans);
	return 0;
}