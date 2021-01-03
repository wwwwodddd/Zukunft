#include <bits/stdc++.h>
using namespace std;
int pw(int x, int y, int p)
{
	int re = 1;
	for (; y; y >>= 1)
	{
		if (y & 1)
		{
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}
int phi(int x)
{
	int re = x;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			re = re / i * (i - 1);
			while (x % i == 0)
			{
				x /= i;
			}
		}
	}
	if (x > 1)
	{
		re = re / x * (x - 1);
	}
	return re;
}
int read(int p)
{
	int re = 0;
	char c;
	while (!isdigit(c = getchar()))
	{
	}
	re = c - '0';
	while (isdigit(c = getchar()))
	{
		re = re * 10 + c - '0';
		if (re >= p)
		{
			re = re % p + p;
		}
	}
	return re;
}
int main()
{
	int a, m;
	scanf("%d%d", &a, &m);
	printf("%d\n", pw(a, read(phi(m)), m));
	return 0;
}