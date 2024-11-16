#include <bits/stdc++.h>
using namespace std;
int n, m, d;
int a[500020];
int b[500020];
int c[500020];
void change(int x, int y)
{
	for (int i = x; i <= n; i += i & -i)
	{
		c[i] += y;
	}
}
int query(int x)
{
	int re = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		re += c[i];
	}
	return re;
}
int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] += a[i - 1] - d;
		b[i] = a[i];
	}
	n++;
	m = n;
	sort(b, b + m);
	m = unique(b, b + m) - b;
	for (int i = 0; i < n; i++)
	{
		a[i] = lower_bound(b, b + m, a[i]) - b + 1;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += query(a[i] - 1);
		change(a[i], 1);
	}
	cout << ans % 92084931 << endl;
	return 0;
}