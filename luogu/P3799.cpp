#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, x, z;
long long c[10020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		c[x]++;
	}
	for (int i = 1; i < 5010; i++)
	{
		z = (z + c[i] * (c[i] - 1) / 2 % p * (c[2 * i] * (c[2 * i] - 1) / 2 % p)) % p;
		for (int j = 1; j < i; j++)
		{
			z = (z + c[i + j] * (c[i + j] - 1) / 2 % p * c[i] % p * c[j]) % p;
		}
	}
	printf("%d\n", z);
	return 0;
}