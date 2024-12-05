#include <bits/stdc++.h>
using namespace std;
int a[200020];
int n, c;
long long z;
int main()
{
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		z += upper_bound(a, a + n, a[i] + c) - lower_bound(a, a + n, a[i] + c);
	}
	printf("%lld\n", z);
	return 0;
}