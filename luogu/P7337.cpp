#include <bits/stdc++.h>
using namespace std;
int n, m, k, b;
int a[10020];
int main()
{
	scanf("%d%d%*d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b);
		if (a[i] == 1 && b == 1)
		{
			k++;
		}
	}
	printf("%d\n", min(n, n - k + m));
	return 0;
}