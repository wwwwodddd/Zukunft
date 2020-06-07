#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
int main()
{
	b = 1;
	while (scanf("%lld/%lld", &c, &d) != EOF)
	{
		a = (a * d + b * c);
		b = b * d;
		d = __gcd(a, b);
		a /= d;
		b /= d;
	}
	if (b < 0)
	{
		a = -a;
		b = -b;
	}
	if (b == 1)
	{
		printf("%lld\n", a);
	}
	else
	{
		printf("%lld/%lld\n", a, b);
	}
	return 0;
}