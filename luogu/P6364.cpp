#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000020];
int l[1000020];
int r[1000020];
long long z;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	l[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] > a[i - 1])
		{
			l[i] = l[i - 1] + 1;
		}
		else if (a[i] == a[i - 1])
		{
			l[i] = l[i - 1];
		}
		else
		{
			l[i] = 1;
		}
	}
	r[n] = 1;
	for (int i = n - 1; i >= 1; i--)
	{
		if (a[i] > a[i + 1])
		{
			r[i] = r[i + 1] + 1;
		}
		else if (a[i] == a[i + 1])
		{
			r[i] = r[i + 1];
		}
		else
		{
			r[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		z += max(l[i], r[i]);
	}
	printf("%lld\n", z);
	return 0;
}