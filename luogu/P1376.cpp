#include <bits/stdc++.h>
using namespace std;
int n, s, c, d = 1e9, y;
long long z;
int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &c, &y);
		d = min(d + s, c);
		z += d * y;
	}
	printf("%lld\n", z);
	return 0;
}