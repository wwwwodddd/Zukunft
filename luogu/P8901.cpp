#include <bits/stdc++.h>
using namespace std;
int p[5000020], pc;
int v[5000020];
int f[5000020];
int g[5000020];
int n = 5000000;
bool isPrime(int x)
{
	return v[x] == 0;
	if (x < 0)
	{
		return false;
	}
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int G(int x)
{
	if (x % 2 == 0)
	{
		return x / 2;
	}
	for (int i = x; i >= 0; i -= 4)
	{
		if (isPrime(i))
		{
			return 1 + (x - i) / 2;
		}
	}
	assert(false);
}
int main()
{
	p[pc++] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == 0)
		{
			p[pc++] = i;
			for (int j = i + i; j <= n; j += i)
			{
				v[j] = 1;
			}
		}
	}
	int t, n, x;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		pair<int, int> wp(1e9, 1e9);
		pair<int, int> lp(1e9, 1e9);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			if (x % 4 == 0)
			{
				lp = min(lp, {G(x) / 2, i});
			}
			else
			{
				wp = min(wp, {G(x) / 2, i});
			}
		}
		if (wp < lp)
		{
			puts("Farmer John");
		}
		else
		{
			puts("Farmer Nhoj");
		}
	}
	return 0;
}