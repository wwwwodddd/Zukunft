#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
int main()
{
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	long long x = c - 2 * b;
	long long y = d - 2 * a - 4 * b;
	if (x == 0 && y == 0)
	{
		puts("-1");
		puts("-1");
	}
	else
	{
		if (x >= 0 && y + 2 >= 0)
		{
			printf("%lld %lld\n", x, y + 2);
		}
		else
		{
			puts("-1");
		}
		if (x + 2 >= 0 && y + 4 >= 0)
		{
			printf("%lld %lld\n", x + 2, y + 4);
		}
		else
		{
			puts("-1");
		}
	}
	return 0;
}