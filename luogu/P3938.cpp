#include <bits/stdc++.h>
using namespace std;
int t;
long long f[70] = {0, 1};
long long x, y;
int main()
{
	for (int i = 2; i < 70; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%lld%lld", &x, &y);
		while (x != y)
		{
			if (x < y)
			{
				swap(x, y);
			}
			x -= *(lower_bound(f, f + 70, x) - 1);
		}
		printf("%lld\n", x);
	}
	return 0;
}