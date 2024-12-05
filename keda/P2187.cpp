#include <bits/stdc++.h>
using namespace std;
int n, d, a[1000020];
long long z;
int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0, j = 0; i < n; i++)
	{
		while (a[i] - a[j] > d)
		{
			j++;
		}
		z += i - j;
	}
	printf("%lld\n", z);
	return 0;
}