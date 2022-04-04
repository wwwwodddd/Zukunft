#include <bits/stdc++.h>
using namespace std;
int a[2000020];
int q[2000020], b, f;
int n, m;
long long z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		while (b < f && a[q[f - 1]] <= a[i])
		{
			f--;
		}
		q[f++] = i;
		while (q[b] <= i - m)
		{
			b++;
		}
		z += a[q[b]];
	}
	printf("%lld\n", z);
	return 0;
}