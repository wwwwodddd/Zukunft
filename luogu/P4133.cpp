#include <bits/stdc++.h>
using namespace std;
long long n, b[120] = {1, 2};
int a[120], c, f, g;
int main()
{
	scanf("%lld", &n);
	for (int i = 2; i <= 88; i++)
	{
		b[i] = b[i - 1] + b[i - 2];
	}
	for (int i = 88; i >= 0; i--)
	{
		if (n >= b[i])
		{
			n -= b[i];
			a[c++] = i;
		}
	}
	reverse(a, a + c);
	f = a[0] / 2;
	g = 1;
	for (int i = 1; i < c; i++)
	{
		g += f;
		f = (a[i] - a[i - 1] - 1) % 2 * f + (a[i] - a[i - 1] - 1) / 2 * g;
	}
	printf("%d\n", f + g);
	return 0;
}