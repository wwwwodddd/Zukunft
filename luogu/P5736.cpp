#include <bits/stdc++.h>
using namespace std;
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
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (isPrime(x))
		{
			printf("%d ", x);
		}
	}
	printf("\n");
	return 0;
}