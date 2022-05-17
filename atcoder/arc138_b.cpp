#include <bits/stdc++.h>
using namespace std;
int n, a[400020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int i = 0, j = n - 1, c = 0;
	for (; i < n; i++)
	{
		if (i % 2 != a[i])
		{
			c = i - 1;
			break;
		}
	}
	for (; j >= i; j--)
	{
		if (a[j] != a[j + 1])
		{
			c--;
		}
	}
	puts(c >= 0 ? "Yes" : "No");
	return 0;
}