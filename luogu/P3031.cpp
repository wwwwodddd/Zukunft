#include <bits/stdc++.h>
using namespace std;
int n, s, t, x, y;
long long z;
int c[200020];
int main()
{
	scanf("%d%d", &n, &x);
	c[s = n] = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &y);
		if (y < x)
		{
			t -= c[s--] - 1;
		}
		else
		{
			t += c[++s] + 1;
		}
		c[s]++;
		z += t;
	}
	printf("%lld\n", z);
	return 0;
}