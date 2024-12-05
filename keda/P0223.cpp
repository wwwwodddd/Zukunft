#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000020];
long long m, s;
int main()
{
	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n, greater<int>());
	for (int i = 0; i <= n; s += a[i++])
	{
		if (s - (long long)a[i] * i >= m)
		{
			printf("%lld\n", (s - m) / i);
			break;
		}
	}
	return 0;
}