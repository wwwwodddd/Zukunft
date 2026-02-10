#include <bits/stdc++.h>
using namespace std;
int n, l, a[1000020], x, z;
int main()
{
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		z = max(z, min(x, l - x));
	}
	printf("%d\n", z);
	return 0;
}