#include <bits/stdc++.h>
using namespace std;
int a[12][4];
int f[16777217];
int d[16777217];
int p[16777217];
int o[16777217];
int u, v, w, x;
set<pair<int, int> > q;
void print(int x)
{
	if (d[x] == 0)
	{
		return;
	}
	print(p[x]);
	printf("%d ", o[x] + 1);
}
int main()
{
	f[0] = 0;
	f[1] = 3;
	f[2] = 2;
	f[3] = 1;
	for (int i = 4; i < 1 << 24; i++)
	{
		f[i] = f[i >> 2] + f[i & 3];
	}
	for (int i = 0; i < 12; i++)
	{
		cin >> x;
		u |= (x - 1) << (2 * i);
		for (int j = 0; j < 4; j++)
		{
			cin >> a[i][j];
			a[i][j]--;
		}
	}
	memset(d, 0x3f, sizeof d);
	d[u] = 0;
	q.insert(make_pair(d[u] * 2 + f[u], u));
	while (q.size())
	{
		u = q.begin()->second;
		q.erase(q.begin());
		if (u == 0)
		{
			break;
		}
		for (int i = 0; i < 12; i++)
		{
			v = u;
			w = u >> (2 * i) & 3;
			int j = a[i][w];
			x = u >> (2 * j) & 3;
			w ^= (w + 1) & 3;
			x ^= (x + 1) & 3;
			v ^= w << (2 * i);
			v ^= x << (2 * j);
			if (d[v] > d[u] + 1)
			{
				q.erase(make_pair(d[v] * 2 + f[v], v));
				d[v] = d[u] + 1;
				p[v] = u;
				o[v] = i;
				q.insert(make_pair(d[v] * 2 + f[v], v));
			}
		}
	}
	printf("%d\n", d[0]);
	print(0);
	printf("\n");
	return 0;
}