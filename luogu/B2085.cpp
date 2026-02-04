#include <bits/stdc++.h>
using namespace std;
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
	int l;
	scanf("%d", &l);
	for (int i = 2;; i++)
	{
		if (isPrime(i))
		{
			if (!--l)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}