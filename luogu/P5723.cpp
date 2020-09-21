#include <bits/stdc++.h>
using namespace std;
int l, c;
bool isPrime(int x)
{
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
	scanf("%d", &l);
	for (int i = 2; i <= l; i++)
	{
		if (isPrime(i))
		{
			printf("%d\n", i);
			l -= i;
			c++;
		}
	}
	printf("%d\n", c);
	return 0;
}