#include <bits/stdc++.h>
using namespace std;
int a[100020], n;
int l[100020], lc;
int c[100020], f;
int mod = 1000000009;
void change(int x, int y)
{
	for (int i = x; i <= lc; i += i & -i)
	{
		c[i] = (c[i] + y) % mod;
	}
}
int query(int x)
{
	int re = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		re = (re + c[i]) % mod;
	}
	return re;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
		l[i] = a[i];
	}
	lc = n + 1;
	sort(l, l + lc);
	lc = unique(l, l + lc) - l;
	for (int i = 0; i <= n; i++)
	{
		a[i] = lower_bound(l, l + lc, a[i]) - l + 1;
	}
	change(a[0], 1);
	for (int i = 1; i <= n; i++)
	{
		change(a[i], f = query(a[i]));
	}
	printf("%d\n", f);
	return 0;
}