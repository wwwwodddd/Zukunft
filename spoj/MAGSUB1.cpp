#include <bits/stdc++.h>
using namespace std;
int t, n;
char s[100020];
bool isPrime(int x)
{
	if (x < 2)
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
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%s", &n, s);
		long long z = 0, l = 0;
		for (int i = 0; i < n; i++)
		{
			if (isPrime(s[i] - 64))
			{
				l = i + 1;
			}
			z += l;
		}
		printf("%lld\n", z);
	}
	return 0;
}