#include <bits/stdc++.h>
using namespace std;
int a[3020];
int b[3020];
int main()
{
	int n;
	scanf("%d", &n);
	a[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3000; j++)
		{
			a[j] *= i;
		}
		for (int j = 0; j < 3000; j++)
		{
			a[j + 1] += a[j] / 10;
			a[j] %= 10;
		}
	}
	int l = 3000;
	while (a[l] == 0)
	{
		l--;
	}
	for (int j = l; j >= 0; j--)
	{
		printf("%d", a[j]);
	}
	printf("\n");
	return 0;
}