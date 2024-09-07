#include <bits/stdc++.h>
using namespace std;
int t[4000020][2], tt;
int r[4000020];
int n, m, x, y;
void insert(int x, int d)
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		if (t[p][x >> i & 1] == 0)
		{
			t[p][x >> i & 1] = ++tt;
		}
		p = t[p][x >> i & 1];
	}
	if (r[p] == 0)
	{
		r[p] = d;
	}
}
int query(int x)
{
	int p = 0, re = 0;
	for (int i = 30; i >= 0; i--)
	{
		if (t[p][x >> i & 1] > 0)
		{
			p = t[p][x >> i & 1];
			re += 1 << i;
		}
		else
		{
			p = t[p][~x >> i & 1];
		}
	}
	return r[p] - 1;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		insert(x, i);
	}
	x = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> y;
		x ^= y;
		cout << query(x) << endl;
	}
	return 0;
}