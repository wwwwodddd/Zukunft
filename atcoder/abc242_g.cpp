#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int a[1000020];
int c[1000020];
int l[1000020];
int r[1000020];
int o[1000020];
int z[1000020];
bool cmp(int x, int y)
{
	return make_pair(l[x] / 1000, r[x]) < make_pair(l[y] / 1000, r[y]);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> l[i] >> r[i];
		o[i] = i;
	}
	sort(o, o + m, cmp);
	int L = 0, R = -1, p = 0;
	for (int i = 0; i < m; i++)
	{
		while (L < l[o[i]])
		{
			p -= --c[a[L++]] & 1;
		}
		while (l[o[i]] < L)
		{
			p += c[a[--L]]++ & 1;
		}
		while (R < r[o[i]])
		{
			p += c[a[++R]]++ & 1;
		}
		while (r[o[i]] < R)
		{
			p -= --c[a[R--]] & 1;
		}
		z[o[i]] = p;
	}
	for (int i = 0; i < m; i++)
	{
		cout << z[i] << endl;
	}
	return 0;
}