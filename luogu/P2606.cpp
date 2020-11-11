#include <bits/stdc++.h>
using namespace std;
int n, p, z = 1, c;
int s[1000020];
int v[1000020];
int main()
{
	scanf("%d%d", &n, &p);
	v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	for (int i = n, j; i > 0; i--)
	{
		s[i]++;
		s[i / 2] += s[i];
		for(j = i; j % p == 0; j /= p)
		{
			c++;
		}
		z = (long long)z * j % p;
		for(j = s[i]; j % p == 0; j /= p)
		{
			c--;
		}
		z = (long long)z * v[j] % p;
	}
	if (c)
	{
		z = 0;
	}
	printf("%d\n", z);
	return 0;
}