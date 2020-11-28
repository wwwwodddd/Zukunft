#include <bits/stdc++.h>
using namespace std;
int x, y, k, m, z;
int d[101][101];
queue<pair<int, int> > q;
void update(int f, int s, int t)
{
	if (d[f][s] == -1)
	{
		if (t <= k)
		{
			z = min(z, abs(f + s - m));
		}
		d[f][s] = t;
		q.push(make_pair(f, s));
	}
}
int main()
{
	scanf("%d%d%d%d", &x, &y, &k, &m);
	memset(d, -1, sizeof d);
	d[0][0] = 0;
	q.push(make_pair(0, 0));
	z = m;
	while (q.size())
	{
		pair<int, int> u = q.front();
		q.pop();
		int f = u.first, s = u.second;
		update(f, 0, d[f][s] + 1);
		update(0, s, d[f][s] + 1);
		update(f, y, d[f][s] + 1);
		update(x, s, d[f][s] + 1);
		update(min(f + s, x), max(0, f + s - x), d[f][s] + 1);
		update(max(0, f + s - y), min(f + s, y), d[f][s] + 1);
	}
	printf("%d\n", z);
	return 0;
}