#include <bits/stdc++.h>
using namespace std;
int n, m, x;
double z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int s = 0, mn = 10, mx = 0;
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &x);
			s += x;
			mn = min(mn, x);
			mx = max(mx, x);
		}
		z = max(z, (s - mn - mx) / (m - 2.));
	}
	printf("%.2f\n", z);
	return 0;
}