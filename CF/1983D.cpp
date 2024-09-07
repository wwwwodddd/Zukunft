#include <bits/stdc++.h>
using namespace std;
int a[200020];
int b[200020];
int c[200020];
void R(int x, int y)
{
	for (; x <= 200000; x += x & -x)
	{
		c[x] += y;
	}
}
int G(int x)
{
	int re = 0;
	for (; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
bool ok()
{
	int n;
	scanf("%d", &n);
	memset(c, 0, sizeof c);
	long long ca = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		ca += G(a[i]);
		R(a[i], 1);
	}
	memset(c, 0, sizeof c);
	long long cb = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		ca += G(b[i]);
		R(b[i], 1);
	}
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1])
		{
			return true;
		}
	}
	return ca % 2 == cb % 2;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		puts(ok() ? "YES" : "NO");
	}
	return 0;
}