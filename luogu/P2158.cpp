#include<stdio.h>
int n, f[40020];
int main()
{
	scanf("%d", &n);
	n--;
	for (int i = 1; i <= n; i++)
	{
		f[i] = (n / i) * (n / i);
	}
	for (int i = n; i >= 1; i--)
	{
		for (int j = 2 * i; j <= n; j += i)
		{
			f[i] -= f[j];
		}
	}
	printf("%d\n", f[1] + (n ? 2 : 0));
	return 0;
}