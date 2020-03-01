#include <bits/stdc++.h>
using namespace std;
long long v[70], x, z;
bool ins(long long x)
{
	for (int i = 62; i >= 0; i--)
	{
		if (x >> i & 1)
		{
			if (!v[i])
			{
				v[i] = x;
				return true;
			}
			x ^= v[i];
		}
	}
	return false;
}
int n; 
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &x);
		ins(x);
	}
	for (int i = 62; i >= 0; i--)
	{
		if (~z >> i & 1)
		{
			z ^= v[i];
		}
	}
	printf("%lld\n", z);
	return 0;
}
