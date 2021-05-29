#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int a[100020];
int b[100020];
int r[100020];
int c[100020];
void mul(int a[], int b[])
{
	for (int i = 1; i <= n; i++)
	{
		c[i] = a[b[i]];
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = c[i];
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
		b[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		reverse(b + x, b + y + 1);
	}
	for (int i = 1; i <= n; i++)
	{
		r[b[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		b[i] = r[i];
	}
	for (; l > 0; l >>= 1)
	{
		if (l & 1)
		{
			mul(a, b);
		}
		mul(b, b);
	}
	for (int i = 1; i <= n; i++)
	{
		r[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = r[i];
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}