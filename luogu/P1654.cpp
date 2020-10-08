#include <bits/stdc++.h>
using namespace std;
int n;
double p, f, g, z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &p);
		z += (3 * f + 3 * g + 1) * p;
		g = (g + 2 * f + 1) * p;
		f = (f + 1) * p;
	}
	printf("%.1f\n", z);
	return 0;
}