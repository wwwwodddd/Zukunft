#include <bits/stdc++.h>
using namespace std;
int t, l, r;
bool isPrime(int n)
{
	if (n < 2)
	{
		return false;
	}
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
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
		scanf("%d %d", &l, &r);
		for (int i = l; i <= r; i++)
		{
			if (isPrime(i))
			{
				printf("%d\n", i);
			}
		}
		printf("\n");
	}
	return 0;
}