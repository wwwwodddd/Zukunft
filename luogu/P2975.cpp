#include <bits/stdc++.h>
using namespace std;
int n;
long long f, g;
int a[700020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = n; i > 0; i--)
	{
		if (f <= g + a[i])
		{
			g += a[i];
			swap(f, g);
		}
	}
	printf("%lld %lld\n", f, g);
	return 0;
}