#include <bits/stdc++.h>
using namespace std;
int n;
int a[100020];
int c[1000020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		c[a[i]]++;
	}
	for (int i = 1000000; i > 0; i--)
	{
		for (int j = 2 * i; j <= 1000000; j += i)
		{
			c[j] += c[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", c[a[i]] - 1);
	}
	return 0;
}