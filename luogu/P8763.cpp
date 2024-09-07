#include <bits/stdc++.h>
using namespace std;
int n;
long long t;
int a[100020];
int main()
{
	scanf("%d%lld", &n, &t);
	for (int i = 0; i < n; i++)
	{
		scanf("%1d", &a[i]);
	}
	for (int i = 0; 1 << i < n; i++)
	{
		if (t >> i & 1)
		{
			for (int j = n - 1; j >= 1 << i; j--)
			{
				a[j] ^= a[j - (1 << i)];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}
