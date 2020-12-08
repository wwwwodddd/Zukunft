#include <bits/stdc++.h>
using namespace std;
int n, z = 1, a[] = {1, 3, 4, 2};
int main()
{
	scanf("%d", &n);
	while (n > 0)
	{
		for (int i = 1; i <= n % 10; i++)
		{
			if (i != 5)
			{
				z = z * i % 10;
			}
		}
		n /= 5;
		z = z * a[n & 3] % 10;
	}
	printf("%d\n", z);
	return 0;
}