#include <bits/stdc++.h>
using namespace std;
long long f[100020];
int n;
long long t, p, v;
int main()
{
	scanf("%d%lld", &n, &t);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld", &p, &v);
		p = -(p + v * t);
		*upper_bound(f, f + n, p) = p;
	}
	printf("%ld\n", lower_bound(f, f + n, 0) - f);
	return 0;
}
