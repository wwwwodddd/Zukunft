#include <bits/stdc++.h>
using namespace std;
int c, p;
long long h, g, f;
int main()
{
	g = 1;
	while (scanf("%1d", &c) != EOF)
	{
		f = g * (c + 1);
		if (p == 1)
		{
			f += h * (9 - c);
		}
		p = c;
		h = g;
		g = f;
	}
	printf("%lld\n", f);
	return 0;
}