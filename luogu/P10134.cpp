#include <bits/stdc++.h>
using namespace std;
int t, n, q, c, x, y;
int a[100020];
int f[100020];
int h[100020];
int b[100020];
int v[100020];
void zuo()
{
	cin >> n >> q >> c;
	memset(a, 0, sizeof a);
	memset(f, 0, sizeof f);
	memset(h, 0, sizeof h);
	memset(b, 0, sizeof b);
	memset(v, 0, sizeof v);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 0)
		{
			v[i] = 1;
		}
	}
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y;
		h[y] = max(h[y], x);
		b[x] = y;
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0)
		{
			if (h[i] > 0)
			{
				a[i] = f[i - 1] + 1;
			}
			else
			{
				a[i] = 1;
			}
		}
		f[i] = max(a[i], f[i - 1]);
		if (a[i] > c)
		{
			cout << -1 << endl;
			return;
		}
	}
	int l = -1, mx = 0;
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == 1)
		{
			l = i;
		}
		if (b[i] > 0 && max(mx, f[i]) < f[b[i] - 1])
		{
			a[l] = f[b[i] - 1];
			mx = max(mx, a[l]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = max(f[i - 1], a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (b[i] > 0 && f[b[i] - 1] >= a[b[i]])
		{
			cout << -1 << endl;
			return;
		}
		if (b[i] > 0 && f[b[i] - 1] > f[i])
		{
			cout << -1 << endl;
			return;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << (i == n ? "\n" : " ");
	}
	return;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		zuo();
	}
	return 0;
}