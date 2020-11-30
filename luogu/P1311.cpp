#include <bits/stdc++.h>
using namespace std;
int n, p, q, x, y;
int l[10020];
int s[10020];
int c[10020];
long long z;
int main()
{
	scanf("%d%*d%d", &n, &p);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		if (y <= p)
		{
			q = i;
		}
		if (q >= l[x])
		{
			s[x] = c[x];
		}
		l[x] = i;
		z += s[x];
		c[x]++;
	}
	printf("%lld\n", z);
	return 0;
}