#include <bits/stdc++.h>
using namespace std;
int t, n, p;
int v[300020];
int main()
{
	n = 300000;
	scanf("%d%d", &t, &p);
	for (int i = 2; i <= n; i++)
	{
		if (!v[i])
		{
			for (int j = i; j <= n; j += i)
			{
				v[j] = 1;
			}
			for (long long j = i; j <= n; j *= i)
			{
				v[j] = i;
			}
		}
	}
	v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		v[i] = (long long)v[i] * v[i - 1] % p;
	}
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		printf("%d\n", v[n]);
	}
	return 0;
}