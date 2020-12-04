#include <bits/stdc++.h>
using namespace std;
char a[20], b[20];
int n, x, y, z;
int g[456976];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s", a, b);
		x = a[0] * 26 + a[1] - 1755;
		y = b[0] * 26 + b[1] - 1755;
		if (x != y)
		{
			z += g[y * 676 + x];
			g[x * 676 + y]++;
		}
	}
	printf("%d\n", z);
	return 0;
}