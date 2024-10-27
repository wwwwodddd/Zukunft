#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m;
int a[500020];
int b[500020];
int c[500020];
void change(int x, int y)
{
	for (int i = x; i <= n; i += i & -i)
	{
		c[i] = (c[i] + y) % p;
	}
}
int query(int x)
{
	int re = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		re = (re + c[i]) % p;
	}
	return re;
}
int main()
{
	scanf("%d", &n);
	m = n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + m);
	m = unique(b, b + m) - b;
	long long z = 0;
	for (int i = 0; i < n; i++)
	{
		a[i] = lower_bound(b, b + m, a[i]) - b + 1;
		int u = query(a[i] - 1) + 1;
		change(a[i], u);
		z = (z + u) % p;
	}
	cout << z << endl;
	return 0;
}