#include <bits/stdc++.h>
using namespace std;
int n, a[100020];
long long z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		z += (2 * i - n + 1LL) * a[i];
	}
	printf("%lld\n", 2 * z);
	return 0;
}