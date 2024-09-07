#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int a[1000020];
int c[1000020];
int l[1000020];
int r[1000020];
int o[1000020];
long long z[1000020];
long long C2(long long x)
{
	return x * (x - 1) / 2;
}
bool cmp(int x, int y)
{
	return make_pair(l[x] / 1000, r[x]) < make_pair(l[y] / 1000, r[y]);
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> l[i] >> r[i];
		o[i] = i;
	}
	sort(o, o + m, cmp);
	int L = 0, R = -1;
	long long p = 0;
	for (int i = 0; i < m; i++)
	{
		while (L < l[o[i]])
		{
			p -= C2(--c[a[L++]]);
		}
		while (l[o[i]] < L)
		{
			p += C2(c[a[--L]]++);
		}
		while (R < r[o[i]])
		{
			p += C2(c[a[++R]]++);
		}
		while (r[o[i]] < R)
		{
			p -= C2(--c[a[R--]]);
		}
		z[o[i]] = p;
	}
	for (int i = 0; i < m; i++)
	{
		cout << z[i] << endl;
	}
	return 0;
}