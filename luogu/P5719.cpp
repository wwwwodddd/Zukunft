#include <bits/stdc++.h>
using namespace std;
int n, k, c;
double s;
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		if (i % k == 0)
		{
			s += i;
			c++;
		}
	}
	printf("%.1f %.1f\n", s / c, (n * (n + 1) / 2 - s) / (n - c));
	return 0;
}