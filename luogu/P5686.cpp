#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, sa, sb, z;
int a[500020], b;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (long long i = 0; i < n; i++)
	{
		scanf("%d", &b);
		sa = (sa + a[i] * (i + 1)) % p;
		z = (z + a[i] * (n - i) % p * sb + b * (n - i) % p * sa) % p;
		sb = (sb + b * (i + 1)) % p;
	}
	printf("%d\n", z);
	return 0;
}