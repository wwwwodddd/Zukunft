#include <bits/stdc++.h>
using namespace std;
long long l, r;
int v[1000020];
int f[1000020];
void gao(int p)
{
	for (long long i = max((l + p - 1) / p, 2LL) * p; i <= r; i += p)
	{
		f[i - l] = 1;
	}
}
int main()
{
	scanf("%lld%lld", &l, &r);
	for (int i = 2; i <= r / i; i++)
	{
		if (!v[i])
		{
			gao(i);
		}
		for (int j = i; j <= r / j; j += i)
		{
			v[j] = i;
		}
	}
	int z = 0;
	for (int i = 0; i <= r - l; i++)
	{
		if (!f[i])
		{
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}